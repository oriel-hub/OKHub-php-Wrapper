<?php

/**
* Class OkhubApiResponse.
*
* Objects of this class contain the data retrieved by the Okhub API calls.
*
*/

class OkhubApiResponse {

  // These properties should be protected, but we need to check first where this class is
  // currently being used, to make sure we don't break the plugins, etc. 

  // Results. Array of IdsApiObject (or its subclasses).
  public $results = array();

  // If the API called did not respond with a well-structured response.
  public $is_error = FALSE;
  public $next_page='';
  public $prev_page='';
  // Flag to indicate if the response is from the cache.
  public $cached = FALSE;

  // Error message, in case an error was produced.
  public $error_message = '';

  // Total results. Number of total results available in the collection.
  public $total_results;

  /**
  * Constructor.
  * 
  * Is called by OkhubApiCall::makeRequest().
  * @param array $results - array with the decoded output of the API call.
  * @param string $format - format of the responses (short, full) (default 'full').
  * @param string $type_results - type of object(s) (documents, organisations, themes, regions, countries).
  * @param string $total_results - total number of results available in the dataset.
  * @param string $default_site - dataset ('eldis', 'bridge').
  * @param bool $cached - indicates if the response was retrieved from the cache.
  * @param array $priorities - array with attributes 'priority_datasource' and 'priority_language'.
  */
  //function __construct($results, $format, $type_results, $total_results, $default_site, $cached = FALSE) {
  function __construct($results, $type_results, $total_results, $default_site, $cached = FALSE, $priorities = FALSE) {
    $this->results = array();
    //$this->next_page=$next_page;
    //$this->prev_page=$prev_page;
    if (!is_array($results)) {
      $this->is_error = TRUE;
      if (is_string($results)) {
        $this->error_message = $results;
      }
    }
    else {
      $this->is_error = FALSE;
      foreach ($results as $object) {      	
        if (!isset($object['site'])) {
          $object['site'] = $default_site;
        }
        if (!isset($object['priorities'])) {
        	$object['priorities'] = $priorities;
        }
        
        $ids_api_object = OkhubApiObject::factory($object, $type_results);
        array_push($this->results, $ids_api_object);
        
      }
    }
    if (isset($total_results)) {
      $this->total_results = $total_results;
    }
    else {
      $this->total_results = 0;
    }
    $this->cached = $cached;
  }

  /**
  * Indicate if the response is empty.
  * @return bool
  */
  function isEmpty() {
    return empty($this->results);
  }

  /**
  * Indicate if the response is an error.
  * @return bool
  */
  function isError() {
    return $this->is_error;
  }

  /**
  * Indicate if the response is from the cache.
  * @return bool
  */
  function isCached() {
    return $this->cached;
  }

  /**
  * Return the error message.
  * @return string.
  */
  function getErrorMessage() {
    return $this->error_message;
  }

  /**
  * Return the results of the response.
  * @return array.
  */
  function getResults() {
    return $this->results;
  }

  /**
  * Return the total results of the response.
  * @return int.
  */
  function getTotalResults() {
    return $this->total_results;
  }

  /**
  * Return an array with an array of retrieved non-archived object's titles.
  * @return array - titles of retrieved items indexed by object_id.
  */
  function getArrayTitles($padding_str = '') {
    $array_objects = array();
    foreach ($this->results as $object) {
     
	//if ((!isset($object->archived)) || ($object->archived !== 'true')) {
		$title="";
		$title = $object->get_value(OKHUB_API_FN_TITLE, $source_id, $language_id);
		if ($padding_str) {
			if (isset($object->level)) {
				$level = $object->level;
				$padding = strlen($title) + strlen($padding_str)*($level - 1);
				$title = str_pad($object->title, $padding, $padding_str, STR_PAD_LEFT);
			} 
		}

		if ($title !== ""){
			$hub_item_id = $object->get_value(OKHUB_API_FN_ITEM_ID, $source_id, $language_id);
			$array_objects['results'][$hub_item_id]['title'] = $title;
		}
	//}
    }
    if ($this->next_page !== 0){	 
    	 $array_objects['metadata']['next_page']=$this->next_page;
    	 //$array_objects['metadata']['next_page_params'] = getUrlParams($this->next_page);
    }
    if ($this->prev_page !== 0){
	 $array_objects['metadata']['prev_page']=$this->prev_page;
    }
    $array_objects['metadata']['total_results'] = $this->total_results;
    
   // print_r($array_objects);
    return $array_objects;
  }
  
  

  /**
  * Create an array with a list of HTML links to the retrieved non-archived objects (eg. titles with links to URLs of OKhub documents/organisations).
  * @return array - titles of retrieved items linked to the online documents (on Eldis or BRIDGE).
  */
  function getArrayLinks($source_id = FALSE, $language_id = FALSE) {
    $list_objects = array();
   foreach ($this->results as $object) {
      if (!$object->get_value(OKHUB_API_FN_ARCHIVED, $source_id, $language_id)) {
      	$list_objects[$object->get_value(OKHUB_API_FN_ITEM_ID, $source_id, $language_id)] = '<a class="' . OKHUB_API_CSS_OBJECT .'" href="' . htmlspecialchars_decode($object->get_value(OKHUB_API_FN_URLS, $source_id, $language_id)) . '">'. $object->get_value(OKHUB_API_FN_TITLE, $source_id, $language_id). '</a>';
      }
    }
    return $list_objects;
  }
  function getBlogEntries($source){
  	$blog_entries =array();
  	foreach($this->results as $i=>$object){
  		$hub_item_id = $object->get_value(OKHUB_API_FN_ITEM_ID, $source_id);
  		if (is_array($source)){
  			foreach($source as $s){
  				$title = $object->get_value(OKHUB_API_FN_TITLE, $s);
  				if ($title){
  					$hub_item_id = $object->get_value(OKHUB_API_FN_ITEM_ID, $s);
					$blog_entries[$s][$hub_item_id]['title'] = $object->get_value(OKHUB_API_FN_TITLE, $s);
					$blog_entries[$s][$hub_item_id]['description'] = $object->get_value(OKHUB_API_FN_DESCRIPTION, $s);
					$blog_entries[$s][$hub_item_id]['url'] = $object->get_value(OKHUB_API_FN_URLS, $s);
					$blog_entries[$s][$hub_item_id]['authors'] = $object->get_value('authors', $s);
					$blog_entries[$s][$hub_item_id]['publisher_country'] = $object->get_value('publisher_country', $s);
					$blog_entries[$s][$hub_item_id]['publisher'] = $object->get_value('publisher', $s);
					$blog_entries[$s][$hub_item_id]['publication_year'] = $object->get_value('publication_year', $s);
					$blog_entries[$s][$hub_item_id]['metadata_url'] = $object->get_value(OKHUB_API_FN_METADATA_URL, $s);
					$blog_entries[$s][$hub_item_id]['hub_themes'] = implode(", ",$object->get_value(OKHUB_API_FN_THEME_DATA, $s));
				}	
  			}			
  		}else{
  			$title = $object->get_value(OKHUB_API_FN_TITLE, $source);
  			if ($title){
					$blog_entries[$source][$hub_item_id]['title'] = $object->get_value(OKHUB_API_FN_TITLE, $source);
					$blog_entries[$source][$hub_item_id]['description'] = $object->get_value(OKHUB_API_FN_DESCRIPTION, $source);
					$blog_entries[$source][$hub_item_id]['url'] = $object->get_value(OKHUB_API_FN_URLS, $source);
					$blog_entries[$source][$hub_item_id]['authors'] = $object->get_value('authors', $source);
					$blog_entries[$source][$hub_item_id]['publisher_country'] = $object->get_value('publisher_country', $source);
					$blog_entries[$source][$hub_item_id]['publisher'] = $object->get_value('publisher', $source);
					$blog_entries[$source][$hub_item_id]['publication_year'] = $object->get_value('publication_year', $source);
					$blog_entries[$source][$hub_item_id]['metadata_url'] = $object->get_value(OKHUB_API_FN_METADATA_URL, $source);
					$blog_entries[$source][$hub_item_id]['hub_themes'] = implode(", ",$object->get_value(OKHUB_API_FN_THEME_DATA, $source));
  				
			}
		}
  	}
  	/*if ($this->next_page !== 0){
  		$blog_entries['metadata']['next_page']=$this->next_page;
  	}
  	if ($this->prev_page !== 0){
  		$blog_entries['metadata']['prev_page']=$this->prev_page;
  	}*/
  	$blog_entries['metadata']['total_results'] = $this->total_results;
  	return $blog_entries;  
  }
 function getDocumentVersion($source){
  	$blog_entries =array();
  	foreach($this->results as $i=>$object){
  		if (is_array($source)){
  			foreach($source as $s){
  				$hub_item_id = $object->get_value(OKHUB_API_FN_ITEM_ID, $s);
  				if ($hub_item_id){
  				//if (!empty($object->titles[$s])){
  					$blog_entries['results'][$hub_item_id]['object_id'] = $hub_item_id;
					$blog_entries['results'][$hub_item_id]['hub_timestamp'] = $object->get_value(OKHUB_API_FN_TIMESTAMP, $s);
					$blog_entries['results'][$hub_item_id]['hub_sources'] = $object->get_value(OKHUB_API_FN_SOURCES, $s);
					$blog_entries['results'][$hub_item_id][$s]['title'] = $object->get_value(OKHUB_API_FN_TITLE, $s);

					$blog_entries['results'][$hub_item_id][$s]['document_medium'] = $object->get_value('document_medium', $s);
					$blog_entries['results'][$hub_item_id][$s]['description'] = $object->get_value(OKHUB_API_FN_DESCRIPTION, $s);
					$blog_entries['results'][$hub_item_id][$s]['url'] = $object->get_value(OKHUB_API_FN_URLS, $s);
					$blog_entries['results'][$hub_item_id][$s]['authors'] = $object->get_value('authors', $s);
					$blog_entries['results'][$hub_item_id][$s]['publisher_country'] = $object->get_value(OKHUB_API_FN_TITLE, $s);
					$blog_entries['results'][$hub_item_id][$s]['publisher'] = $object->get_value('publisher_country', $s);
					$blog_entries['results'][$hub_item_id][$s]['publication_year'] = $object->get_value('publication_year', $s);
					$blog_entries['results'][$hub_item_id][$s]['metadata_url'] = $object->get_value(OKHUB_API_FN_METADATA_URL, $s);
					$blog_entries['results'][$hub_item_id][$s]['hub_themes_inline'] = implode(",",$object->get_value(OKHUB_API_FN_THEME_DATA, $s));
					$blog_entries['results'][$hub_item_id][$s]['hub_themes'] = $object->get_value(OKHUB_API_FN_THEME_DATA, $s);
					//$blog_entries['results'][$hub_item_id][$s]['hub_country'] = $object->hub_country;
					$blog_entries['results'][$hub_item_id][$s]['date_created'] = $object->get_value(OKHUB_API_FN_DATE_CREATED, $s);
					$blog_entries['results'][$hub_item_id][$s]['date_updated'] = $object->get_value(OKHUB_API_FN_DATE_UPDATED, $s);
					//$blog_entries['results'][$hub_item_id][$s]['country_focus'] = implode(",",$object->country_focus[$s]);
					$blog_entries['results'][$hub_item_id][$s]['hub_country'] = $object->get_value(OKHUB_API_FN_TITLE, $s);
					$blog_entries['results'][$hub_item_id][$s]['country_focus'] = $object->get_value(OKHUB_API_FN_TITLE, $s);
					$blog_entries['results'][$hub_item_id][$s]['hub_region'] = $object->get_value(OKHUB_API_FN_TITLE, $s);
					$blog_entries['results'][$hub_item_id][$s]['category_theme_array'] = $object->get_value(OKHUB_API_FN_THEME_DATA, $s);
					$blog_entries['results'][$hub_item_id][$s]['category_subject_array'] = $object->get_value(OKHUB_API_FN_SUBJECT_DATA, $s);
					$blog_entries['results'][$hub_item_id][$s]['category_region_array'] = $object->get_value(OKHUB_API_FN_REGION_DATA, $s);
					$blog_entries['results'][$hub_item_id][$s]['country_focus_array'] = $object->get_value(OKHUB_API_FN_COUNTRY_DATA, $s);				
				}else{
					//echo $s;	
				}
  			}			
  		}
  	}
  	/*if ($this->next_page !== 0){
  		$blog_entries['metadata']['next_page']=$this->next_page;
  	}
  	if ($this->prev_page !== 0){
  		$blog_entries['metadata']['prev_page']=$this->prev_page;
  	}*/
  	$blog_entries['metadata']['total_results'] = $this->total_results;
  	return $blog_entries;  
  }
  function getAllList($source_type){
  	$list = array();
  	foreach($this->results as $object){
  		$id = $hub_item_id;
  		$title = $object->get_value(OKHUB_API_FN_TITLE);
  		if ($title){
  			$list[$source_type][$id]['title'] = $title;
  			$iso_two_letter_code =  $object->get_value('iso_two_letter_code');
  			if ($iso_two_letter_code && ($source_type=="countries")){
  				$list[$source_type][$id]['iso_two_letter_code'] = $iso_two_letter_code;
			}
			$list[$source_type][$id]['metadata_url'] = $object->get_value(OKHUB_API_FN_METADATA_URL);
  		}
		
  	}
  	return $list;
  }


} // OkhubApiResponse










  