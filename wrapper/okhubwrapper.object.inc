<?php

/**
 * OkhubApiObject class.
 *
 * Objects of this class' inherited classes contain the information of assets (documents and organisations), categories (regions and themes)
 * and countries available in the Okhub datasets.
 *
 */
class OkhubApiObject {
  
  // Title of the object.
  public $hub_data;

  /**
   * Factory method used to create OkhubApiObject objects, depending on its type.
   *
   * @return a new OkhubApiObject object
   */
  // TODO: Check parameters. $format not used any more???
  public static function factory($object, $object_type) {
    switch ($object_type) {
      case 'assets': //not in use for okhub
        return new OkhubApiObjectAsset($object);
      case 'documents':      	      
        return new OkhubApiObjectAssetDocument($object);
      case 'organisations':
        return new OkhubApiObjectAssetOrganisation($object);
      case 'themes':
        return new OkhubApiObjectCategory($object);
      case 'subjects':
        return new OkhubApiObjectCategory($object);
      case 'regions':
        return new OkhubApiObjectCategory($object);
      case 'countries':
        return new OkhubApiObjectCountry($object);
      case 'sources':
        return new OkhubApiObjectSource($object);
      case 'country_count':
      case 'theme_count':
      case 'region_count':
      case 'subject_count':
      case 'keyword_count':
      case 'source_count':
        return new OkhubApiCount($object, $object_type);
      default:
        return new OkhubApiObject($object);
    }
  }
 
  /**
   * Constructor.
   */
  public function __construct($object) {
   // $this->build_public_vars($object);
    $this->hub_data = $object;
  }
  
  public function build_public_vars($object){
	foreach($this as $var => $value) {
	    if (isset($object[$var]) && $var!='hub_data'){
	    	$this->{$var} = $object[$var];
	    }
    }   	
  }
  
  public function get_value_object($field_name){
    if (isset($this->hub_data[$field_name])){
    	return $this->hub_data[$field_name];
    }  
    return FALSE; 	
  }
  
  public function get_value($field_name){
    /*
     * Get the value for this field/attribute selects from the priority source/language
     * if available or a fallback if not
     */
  	//print('GETVALUE:'.$field_name.':');
  	$value_obj = $this->get_value_object($field_name);
  	if (isset($this->hub_data['priorities'])) {
    	$source_id = $this->hub_data['priorities']['priority_datasource'];
    	$language_id = $this->hub_data['priorities']['priority_language'];
    } else {
    	//print('no priorities');
    	return $value_obj;
    }
  	if ($value_obj){
  		//print_r($value_obj);
    	if(is_array($value_obj)){
    		$choosen_obj = FALSE;
    		$fallback_obj = FALSE;
    		/* See if there is a hub value */
    		if(isset($value_obj['hub'])){
    			$choosen_obj = $value_obj['hub'];
    			//print('hubfound:');
    		} else {
	    		/* If not see if there is an item for the choosen priority source */
	    		foreach($value_obj as $source => $lang_obj){
	    			if($source == $source_id){
	    				$choosen_obj = $lang_obj;
	    				//print('objfound:');
	    			}
	    			$fallback_obj = $lang_obj;
	    		}
	    		/* If not use a fallback */
	    		if(!$choosen_obj){
	    			$choosen_obj = $fallback_obj;
	    		}
	    		//print_r($choosen_obj);
    		}
    		/* See if there is an item for the choosen priority language */
    		if($choosen_obj){
	    		$choosen_value = FALSE;
	    		$fallback_value = FALSE;
	    	   	foreach($choosen_obj as $lang => $value){
	    			if($lang == $language_id){
	    				//print('langfound:');
	    				$choosen_value = $value;
	    			}
	    			$fallback_value = $value;
	    		}
    		   	/* If not use a fallback */
	    		if(!$choosen_value){
	    			$choosen_value = $fallback_value;
	    		}
	    		if($choosen_value){
	    			//print('GOTIT:');
	    			/* 
	    			 * this is what we are actually after! 
	    			 * the other stuff is sent back for debug or are for fields that
	    			 * dont use the standard [source][language] structure
	    			 * 
	    			 * Note: If it's an Array and only one element then return as string,
	    			 * should we do this?? Most things are just single value so I think this 
	    			 * makes it work better for the Drupal module, but can change that
	    			 * */
	    			if(is_array($choosen_value)){
	    				if(count($choosen_value) == 1){
	    					if(isset($choosen_value[0])){
	    						$choosen_value = $choosen_value[0];
	    						//print('TOSTR:');
	    					}
	    				}
	    			}
	    			//print($choosen_value);
	    			return $choosen_value;
	    		} else {
	    			return $choosen_obj;
	    		}
    		} else {
    			return $value_obj;
    		}
    	} else {
    		return $value_obj;
    	}
    }   
    return FALSE;	
  }

}

/**
 * OkhubApiObjectAsset class.
 * 
 * This class extends OkhubApiObject and is inherited by OkhubApiObjectAssetDocument and OkhubApiObjectAssetOrganisation.
 *
 */
abstract class OkhubApiObjectAsset extends OkhubApiObject {
  /**
   * Constructor.
   */
  public function __construct($object) {
    parent::__construct($object);
  }

}

/**
 * OkhubApiObjectAssetDocument class.
 * 
 * The objects of this class contain the information of documents in the IDS collection.
 *
 */
class OkhubApiObjectAssetDocument extends OkhubApiObjectAsset {
  /**
   * Constructor.
   */
  public function __construct($object) {
    parent::__construct($object);
  }

}

/**
 * OkhubApiObjectAssetOrganisation class.
 * 
 * The objects of this class contain the information of organisations in the OKHUB collection.
 *
 */
class OkhubApiObjectAssetOrganisation extends OkhubApiObjectAsset {
  /**
   * Constructor.
   */
  public function __construct($object) {
    parent::__construct($object);
  }

}

/**
 * OkhubApiObjectObjectCategory class.
 * 
 * The objects of this class contain the information of regions and themes in the IDS collection.
 *
 */
class OkhubApiObjectCategory extends OkhubApiObject  {
  // Indicates if the category is archived.
  public $archived = FALSE;

  /**
   * Constructor.
   */
  function __construct($object) {
    parent::__construct($object);
  }

}

/**
 * OkhubApiObjectCountry class.
 * 
 * The objects of this class contain the information of countries in the IDS collection.
 *
 */
 
class OkhubApiObjectCountry extends OkhubApiObject {
  /**
   * Constructor.
   */
  function __construct($object) {
    parent::__construct($object);
  }

}


/**
 * OkhubApiObjectSource class.
 * 
 * The objects of this class contain the information of all thhe sources from the OKhub collection.
 *
 */
 
class OkhubApiObjectSource extends OkhubApiObject {
  // Source code ID
  public $code;
  public $name;
  public $title;
  // Type of source (semantic etc...)
  public $okhub_is;
  /**
   * Constructor.
   */
  function __construct($object) {
    parent::__construct($object);
    if (isset($object['okhub'])) {
     if (isset($object['okhub']['code'])) {
		$this->code = $object['okhub']['code'];
     }
     if (isset($object['okhub']['name'])) {
		$this->name = $object['okhub']['name'];
     }
     if (isset($object['okhub']['title'])) {
		$this->title = $object['okhub']['title'];
     }
    }
    if (isset($object['okhub_is'])) {
		$this->okhub_is = $object['okhub_is'];
     }
  }

}


/**
 * OkhubApiCount class.
 *
 * Objects of this class hold one result of a count request.
 *
 */
class OkhubApiCount {

  // Number of responses corresponding to the category.
  public $count;

  // This is an OkhubApiObject representing the category (in the case of theme, subject and region OkhubApiObjectCategory and for country OkhubApiObjectCountry).
  public $item;

  /**
   * Constructor.
   */
  function __construct($object, $type) {
    if (isset($object['count'])) {
      $this->count = $object['count'];
    }
    switch ($type) {
      case 'country_count':
        $this->item = new OkhubApiObjectCountry($object);
        break;
      case 'theme_count':
      case 'region_count':
      case 'subject_count':
        $this->item = new OkhubApiObjectCategory($object);
        break;
      default:
        $this->item = new OkhubApiObject($object);
        break;
    }
  }

}