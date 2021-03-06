<?php

/**
* Class OkhubApiWrapper.
* 
* Objects of this class are used to retrieve content in the OKHUB collections  through the OKHUB API.
* Used the original OKHUB Wrapper
* 
*/

require_once('okhubwrapper.default.inc'); 
require_once('okhubwrapper.object.inc'); 
require_once('okhubwrapper.request.inc'); 
require_once('okhubwrapper.response.inc');

if (!defined('OKHUB_API_ENVIRONMENT')) define('OKHUB_API_ENVIRONMENT', 'generic');

switch (OKHUB_API_ENVIRONMENT) {
  case 'drupal':
    require_once('cms/okhubwrapper.drupal.inc');
    break;
  case 'wordpress':
    // In this case we also include the generic functions.
    require_once('cms/okhubwrapper.wordpress.inc');
  default:
    require_once('okhubwrapper.generic.inc');
}

class OkhubApiWrapper {

  // Current request object.
  private $request;
  
  // Sources full data.
  private $sources_data;
  
  // Sources simple array code=>name
  private $sources_options;
  
  // Sources data with full objects 
  private $sources_options_objects;

  /**
  * Constructor
  */
  function __construct() {
    $this->request = new OkhubApiRequest();
  }

  /**
  * Method used to set the token guid of the items to request.
  * @param string $api_key - OKHUB API token guid.
  */
  public function setApiKey($api_key) {
    $this->request->setApiKey($api_key);
  }

  /**
  * Method used to set the "site" parameter of the request.
  * @param string $set - dataset from where to retrieve the information (originally eldis, bridge, right now its hub).
  */
  public function setSite($site) {
    $this->request->setSite($site);
  }
  
  /**
  * Method used to set the "Priority Source" parameter of the request.
  * @param string $set - data source used as preference for return
  */
  public function setPriorityDatasource($source_id) {
    $this->request->setPriorityDatasource($source_id);
  }
  
  /**
  * Method used to set the "Priority Language" parameter of the request.
  * @param string $set - language used as preference for return
  */
  public function setPriorityLanguage($lang_id) {
    $this->request->setPriorityLanguage($lang_id);
  }

  /**
  * Set the type of the request.
  * @param string $type_request - type of the request (search, get, get_all).
  * 
  */
  public function setTypeRequest($type_request) {
    $this->request->setTypeRequest($type_request);
  }

  /**
  * Set the format of the response.
  * @param string $format - format of the response (id, short, full).
  */
  public function setFormat($format) {
    $this->request->setFormat($format);
  }

  /**
  * Method used to set the "num_requested" parameter of the request.
  * @param int $num_requested - the number of results requested (default 0, means all available results).
  */
  public function setNumRequested($num_requested) {
    $this->request->setNumRequested($num_requested);
  }

  /**
  * Method used to set the "age_results" parameter of the request.
  * @param int $age_results - only results published in this last number of days are retrieved (default 0, means no limit).
  */
  public function setAgeResults($age_results) {
    $this->request->setAgeResults($age_results);
  }

  /**
  * Set the offset for the request.
  * @param int $start_offset - offset for the results of the request.
  */
  public function setOffset($start_offset) {
    $this->request->setOffset($start_offset);
  }

  /**
  * Method used to set the "object_type" parameter of the request.
  * @param string $type - type of object(s) requested (documents, organisations, themes, regions, countries).
  */
  public function setObjectType($object_type) {
    $this->request->setObjectType($object_type);
  }

  /**
  * Set the category in count requests.
  * @param string $count_category - category (theme, region, country, keyword, subject).
  */
  public function setCountCategory($count_category) {
    $this->request->setCountCategory($count_category);
  }

  /**
  * Method used to set additional parameters of the request.
  * @param array $params - unencoded filters to be added to the request (eg. array('publisher' => 'UNDP', 'country' => 'Costa Rica|Nicaragua')).
  */
  public function setParameters($params) {
    foreach ($params as $key => $value) {
      $this->setParam($key, $value);
    }
  }

  /**
  * Method used to set additional parameters of the request.
  * @param string $key - parameter.
  * @param string $value - value of the parameter.
  */
  public function setParam($key, $value) {
    $this->request->setParam($key, $value);
  }

  /**
  * Method that receives a comma-separated query string and sets the corresponding parameters.
  * @param array $query - query string (eg. "country = Argentina, keyword = climate change, language_name = Spanish")
  */
  public function setQueryString($query_string) {
    $search_params = explode(',', $query_string);
    foreach ($search_params as $search_param) {
      list ($key, $value) = explode('=', trim($search_param));
        $this->setParam($key, $value);
    }
  }

  /**
  * Method used to set additional fields to be included in the response to the request.
  * @param array $extra_fields - extra fields to be returned (in short responses). (eg. array('headline', 'category_theme_array')).
  */
  public function setExtraFields($extra_fields) {
    foreach ($extra_fields as $field) {
      $this->setExtraField($field);
    }
  }

  /**
  * Method used to set additional fields to be included in the response to the request.
  * @param string $field - extra field to be included in the response.
  */
  public function setExtraField($field) {
    $this->request->setExtraField($field);
  }

  /**
  * Method used to retrieve a set of OKHub items (by a 'search' request to the API).
  *
  * @param string $object_type - type of object(s) requested (documents, organisations, themes, regions, countries, subjects).
  * @param string $site - dataset from where to retrieve the information (hub).
  * @param string $api_key - Iokhub API token guid.
  * @param string $format - format of the responses (short, full) (default 'full').
  * @param int $num_requested - the number of results requested (default 0, means all available results).
  * @param int $age_results - only results published in this last number of days are retrieved (default 0, means no limit).
  * @param array $params - unencoded filters to be added to the request (eg. array('publisher' => 'UNDP', 'country' => 'Costa Rica|Nicaragua')).
  * @param array $extra_fields - extra fields to be returned (in short responses). (eg. array('headline', 'category_theme_array')).
  * @param array $priorities - array with attributes 'priority_datasource' and 'priority_language'.
  * @return OkhubApiResponse - response object holding the data retrieved by the API call.
  */
  public function search($object_type, $site, $api_key, $format = 'full', $num_requested = 0, $age_results = 0, $start_offset = 0, $params = array(), $extra_fields = array(), $priorities = FALSE) {
    $this->request = new OkhubApiRequest();
    $this->request->setTypeRequest('search');
    $this->request->setApiKey($api_key);
    $this->request->setSite($site);
    $this->request->setFormat($format);
    $this->request->setNumRequested($num_requested);
    $this->request->setAgeResults($age_results);
    $this->request->setObjectType($object_type);
    $this->request->setOffset($start_offset);
    $this->setParameters($params);
    $this->setExtraFields($extra_fields);
    if($priorities){
    	if(isset($priorities['priority_datasource'])){
    		$this->request->setPriorityDatasource($priorities['priority_datasource']);
    	}
        if(isset($priorities['priority_language'])){
    		$this->request->setPriorityLanguage($priorities['priority_language']);
    	}
    }
    $response = $this->makeRequest();
    return $response;
  }

  /**
  * Method used to retrieve one item in the OKHub (by a 'get' request to the API).
  * @param string $object_type - type of object(s) requested (documents, organisations, themes, regions, countries, subjects).
  * @param string $site - dataset from where to retrieve the information (hub).
  * @param string $api_key - OKHUB API token guid.
  * @param string $format - format of the responses (short, full) (default 'full').
  * @param string $object_id - object_id value of the object to be retrieved.
  * @param array $priorities - array with attributes 'priority_datasource' and 'priority_language'.
  * @return OkhubApiResponse - response object holding the data retrieved by the API call.
  */
  public function get($object_type, $site, $api_key, $format = 'full', $object_id, $priorities = FALSE) {
    $this->request = new OkhubApiRequest();
    $this->request->setTypeRequest('get');
    $this->request->setApiKey($api_key);
    $this->request->setSite($site);
    $this->request->setFormat($format);
    $this->request->setObjectType($object_type);
    $this->request->setObjectId($object_id);
    if($priorities){
    	if(isset($priorities['priority_datasource'])){
    		$this->request->setPriorityDatasource($priorities['priority_datasource']);
    	}
        if(isset($priorities['priority_language'])){
    		$this->request->setPriorityLanguage($priorities['priority_language']);
    	}
    }
    $response = $this->makeRequest();
    return $response;
  }

  /**
  * Method used to retrieve all items of a specific type in the OKHub (by a 'get_all' request to the API).
  * @param string $object_type - type of object(s) requested (documents, organisations, themes, regions, countries, subjects).
  * @param string $site - dataset from where to retrieve the information (eldis, bridge).
  * @param string $api_key - OKHUB API token guid.
  * @param string $format - format of the responses (short, full) (default 'full').
  * @param array $priorities - array with attributes 'priority_datasource' and 'priority_language'.
  * @return OkhubApiResponse - response object holding the data retrieved by the API call.
  */
  public function getAll($object_type, $site, $api_key, $format = 'full', $priorities = FALSE) {
    $this->request = new OkhubApiRequest();
    $this->request->setTypeRequest('get_all');
    $this->request->setApiKey($api_key);
    $this->request->setSite($site);
    $this->request->setFormat($format);
    $this->request->setObjectType($object_type);
    if($priorities){
    	if(isset($priorities['priority_datasource'])){
    		$this->request->setPriorityDatasource($priorities['priority_datasource']);
    	}
        if(isset($priorities['priority_language'])){
    		$this->request->setPriorityLanguage($priorities['priority_language']);
    	}
    }
    $response = $this->makeRequest();
    return $response;
  }

  /**
  * Method used to count the number of hits within the search that match a category.
  * @param string $object_type - type of object(s) requested (items, documents, organisations).
  * @param string $site - dataset from where to retrieve the information (eldis, bridge).
  * @param string $api_key - OKhub API token guid.
  * @param string $count_category - category (theme, region, country, keyword, subject).
  * @param array $params - unencoded filters to be added to the request (eg. array('publisher' => 'UNDP', 'country' => 'Costa Rica|Nicaragua')).
  * @return OkhubApiResponse - response object holding the data retrieved by the API call.
  */
  public function count($object_type, $site, $api_key, $count_category, $age_results = 0, $params=array()) {
    $this->request = new OkhubApiRequest();
    $this->request->setTypeRequest('count');
    $this->request->setApiKey($api_key);
    $this->request->setSite($site);
    $this->request->setCountCategory($count_category);
    $this->request->setObjectType($object_type);
    $this->request->setAgeResults($age_results);
    $this->setParameters($params);
    $response = $this->makeRequest();
    return $response;
  }

  /**
  * Make a call to the API in order to validate the key.
  * @param string $api_key - Okhub API token guid.
  * @return bool - true if the key is valid, false otherwise.
  */
  public function validateKey($api_key) {
    return (!$this->search('regions', OKHUB_API_DEFAULT_DATASET, $api_key, 'short', 1)->isEmpty());
  }

  /**
  * Make a call to the API in order to determine if fields available only to partners (such as "subjects") can be accessed.
  * @param string $api_key - OKHub API token guid.
  * @return bool - true if the request retrieved results, false otherwise.
  */
  public function additionalFieldsAvailable($api_key) {
    return (!$this->search('documents', OKHUB_API_DEFAULT_DATASET, $api_key, 'short', 1, 0, 0, array('extra_fields' => 'category_subject_array'))->isEmpty());
  }


  /**
  * Builds the URL, checks if the request is in the cache, and if not makes the call and saves it in the cache.
  * @return OkhubApiResponse - response object holding the data retrieved by the API call.
  */
  public function makeRequest() {
    $cached = FALSE;
    // Build the URL.
    $this->request->setUrl();
    $object_type = $this->request->getObjectType();
    // Check if it's in the cache.  If it's not, make the call and save it in the cache.
    /**/
    if ($data = $this->cacheGet()) {
      $cached = TRUE;
      list($results, $total_results, $next_page, $prev_page) = $data;
    }
    else {/**/
      if ($this->request->getTypeRequest() == 'count') {
        list($results, $total_results, $next_page, $prev_page) = $this->getDecodedCountResults($this->getUrl());
        $object_type = $this->request->getCountCategory() . '_count';
      }
      else {
        list($results, $total_results, $next_page, $prev_page) = $this->getDecodedResults($this->getUrl(), 0);
      }
      $this->cacheSet(array($results, $total_results, $next_page, $prev_page));
    }
    $priorities = array(
    	'priority_datasource' => $this->request->getPriorityDatasource(),
    	'priority_language' => $this->request->getPriorityLanguage()
    );
    $response = new OkhubApiResponse($results, $object_type, $total_results, $this->request->getSite(), $cached, $priorities, $next_page, $prev_page);
    return $response;
  }

  /**
  * Retrieve the request's url (if set).
  * @return string -  URL of the API request.
  */
  public function getUrl() {
    return $this->request->getUrl();
  }


  /**
  * Make the API call for count requests.
  * @param string $url - API URL to get the data from.
  * @return array - array containing two elements: an array with the 'count' part of the response and 
  *                 the total number of results available in the dataset (as indicated in the 'metadata' part of the response).
  */
  protected function getDecodedCountResults($url) {
    $data = $this->getResponseData($url);
    $prev_page = $next_page=0;
    if (is_array($data) && !empty($data)) {
      $metadata = $this->getResponseMetadata($data);
      $total_results = $metadata['total_results'];
      if (isset($metadata['next_page'])){
      	      $next_page = $metadata['next_page'];
      }
      if (isset($metadata['prev_page'])){
      	      $prev_page = $metadata['prev_page'];
      }
      $results = $this->getCountResults($data);
    }
    else {
      $results = $data;
      $total_results = 0;
    }
    return array($results, $total_results, $next_page, $prev_page);
  }

  /**
  * Make the actual API calls, implementing pagination and returning the decoded data.
  * @param string $url - API URL to get the data from.
  * @param int $num_retrieved - number of items retrieved so far (initially, 0).
  * @return array - array containing two elements: an array with the 'results' part of the response and 
  *                 the total number of results available in the dataset (as indicated in the 'metadata' part of the response).
  */
  protected function getDecodedResults($url, $num_retrieved) {
    $prev_page = $next_page=0;
    $data = $this->getResponseData($url);
    if (is_array($data) && !empty($data)) {
      $results = $this->getResponseResults($data);
      $metadata = $this->getResponseMetadata($data);
      if (isset($metadata['next_page'])){
      	      $next_page = $metadata['next_page'];
      }
      if (isset($metadata['prev_page'])){
      	      $prev_page = $metadata['prev_page'];
      }      
      $total_results = $metadata['total_results'];
      $num_results = count($results);
      $num_retrieved += $num_results;
      if (($total_results > $num_retrieved) && (($num_retrieved < $this->request->getNumRequested()) || ($this->request->getNumRequested() == 0))) {
        if (isset($metadata['next_page'])) {
          $next_page_url = $metadata['next_page'];
          list($new_results) = $this->getDecodedResults($next_page_url, $num_retrieved);
        
          if (is_array($new_results)) {
            $results = array_merge_recursive($results, $new_results);
            
          }
        }
      }
    }
    else {
      $results = $data;
      $total_results = 0;
    }
    return array($results, $total_results, $next_page,$prev_page);
     //return array($results, $total_results);
  }

  /**
  * Retrieve the URL.
  * We check first if there is a function that overrides this functionality (as in the case of Wordpress or Drupal).
  * @param string $url - API URL to get the data from.
  * @return array $data - array containing the decoded JSON object retrieved by the API call.
  */
  protected function getResponseData($url) {
    // In certain environments (such as Drupal or Wordpress) specific implementations of this function can be provided.
    if (function_exists('okhubapi_get_data')) {
      $data = okhubapi_get_data($url);
    }
    // If cURL is available, we use it.
    elseif (function_exists('curl_init')) {
      $ch = curl_init($url);
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
      $content = curl_exec($ch);
      curl_close($ch);
      $data = json_decode($content, true);
      if (is_array($data) && isset($data['detail'])) {
        $data = $data['detail'];
      }
    }
    // Otherwise, we use file_get_contents.
    else {
      $content = @file_get_contents($url);
      if (!$content) {
        $error = error_get_last();
        $data = preg_replace('/(.*) (HTTP.*)/', '$2', $error['message']);
      }
      else {
        $data = json_decode($content, true);
      }
    }
    return $data;
  }

  /**
  * Get the results part of the response.
  * @param array $results - array containing the 'results' part of the response.
  * @return array $data - array containing the decoded JSON object retrieved by the API call.
  */
  protected function getResponseResults($data) {
    $results = array();
    if (isset($data['results'])) {
      $results = $data['results'];
      if (isset($results['object_id'])) { //When there's only one response
        $results = array($results);
      }
    }
    return $results;
  }

  /**
  * Get the count part of the response for count requests.
  * @param array $results - array containing the 'count' part of the response.
  * @return array $data - array containing the decoded JSON object retrieved by the API call.
  */
  protected function getCountResults($data) {
    $results = array();
    $results_field = $this->request->getCountCategory() . '_count';
    if (isset($data[$results_field])) {
      $results = $data[$results_field];
    }
    return $results;
  }

  /**
  * Get the metadata part of the response.
  * @param array $results - array containing the 'results' part of the response.
  * @return array $metadata - array containing the decoded JSON object retrieved by the API call.
  */
  protected function getResponseMetadata($data) {
    $metadata = array();
    if (isset($data['metadata'])) {
      $metadata = $data['metadata'];
    }
    else {
      $metadata['total_results'] = 1;
    }
    return $metadata;
  }
  
  /**
  * Retrieve the cache.
  * @return string - text of the cached response corresponding to the current request.
  */
  protected function cacheGet() {
    static $items = array();
    $cid = $this->cacheId();
    if (!isset($items[$cid])) {
      $items[$cid] = okhubapi_cache_get($cid, OKHUB_API_CACHE_REQUESTS);
    }
    return $items[$cid];
  }

  /**
  * Populate the cache.
  * @param array $data - text of the response corresponding to the current request to be cached.
  */
  protected function cacheSet($data) {
    if (!$data[1]) {
      // If we get an empty response we set a 5 min. temporary cache to avoid making repeated failed requests in a short period of time.
      okhubapi_cache_set($this->cacheId(), $data, OKHUB_API_CACHE_REQUESTS, 300);
    }
    else {
      okhubapi_cache_set($this->cacheId(), $data, OKHUB_API_CACHE_REQUESTS, OKHUB_API_DEFAULT_CACHE_TIME);
    }
  }

  /**
  * Generate a cache item id based on the hash of the url of the current request.
  * @return string - id by which to identify the cached response of the current request.
  */
  protected function cacheId() {
    return get_class($this) .':'. md5($this->getUrl());
  }

  /**
  * Delete the cache entry for the current request.
  */
  public function cacheClear() {
    okhubapi_cache_clear($this->cacheId());
  }

  /**
  * Delete all the cache entries.
  */
  public function cacheFlush() {
    okhubapi_cache_flush();
  }
  
  /*
   * JoeMcP -- the following functions were pulled from the OKhub Drupal module
   * these helper functions could be usefull for other apps such as a Wordpress plugin
   */
  
	/**
	 * Get array of all sources in the form key=source code, value=source name
	 */
	public function okhubapi_get_sources_options($api_key, $full_data = FALSE){
	    $this->okhubapi_get_full_sources_data($api_key);
	    if(!$this->sources_options || $full_data){
		    $this->sources_options = array();
		    if($this->sources_data){
			    foreach($this->sources_data as $source){
			    	unset($source->hub_data['']);
			    	$is_semantic = FALSE;
		    		if($source->get_value('is_semantic')){
		    			$is_semantic = TRUE;
		    		}
			    	if($source->get_value(OKHUB_API_FN_SOURCE_CODE) && $source->get_value(OKHUB_API_FN_NAME) && !$is_semantic){
			    		$this->sources_options[$source->get_value(OKHUB_API_FN_SOURCE_CODE)] = ($full_data) ? $source:$source->get_value(OKHUB_API_FN_NAME);
			    	}
			    }
		    }
		    asort($this->sources_options);
	    }
	 	return $this->sources_options;
	}
	
	/**
	 * Get array of all sources in the form key=source code, value=source object
	 */
	public function okhubapi_get_sources_options_objects($api_key){
		if(!$this->sources_options_objects){
		   $this->sources_options_objects = $this->okhubapi_get_sources_options($api_key, TRUE);
	    }
	 	return $this->sources_options_objects;
	}
	
	/*
	 * function to get full source data from api and store in static (as not often to change)
	 */
	public function okhubapi_get_full_sources_data($api_key){
		if(!$this->sources_data){
			$cache_sources_response = okhubapi_cache_get(OKHUB_API_SOURCES_CACHE_FILE_ID, OKHUB_API_CACHE_REQUESTS);
			if(isset($cache_sources_response->results)){
				$sources_response = $cache_sources_response;
			} else {
  				$sources_response = $this->getAll('sources', OKHUB_API_DEFAULT_DATASET, $api_key, 'full');
  				okhubapi_cache_set(OKHUB_API_SOURCES_CACHE_FILE_ID, $sources_response, OKHUB_API_CACHE_REQUESTS, OKHUB_API_DEFAULT_CACHE_TIME);
			}
			if(isset($sources_response->results)){
				$this->sources_data = $sources_response->results;
			}
		}
		return $this->sources_data;
	}
	
	/*
	 * function to get source name from id 
	 */
	public function okhubapi_get_source_name_from_id($source_id, $api_key){
	  	$this->okhubapi_get_sources_options($api_key);
		if(isset($this->sources_options[$source_id])){
			return $this->sources_options[$source_id];
		}
		return false;
	}

} // Class OKhubApiWrapper
