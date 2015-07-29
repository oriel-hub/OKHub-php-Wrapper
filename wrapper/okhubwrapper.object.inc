<?php

/*
 * Iso country data
 */

/*
 * country data obtained from http://www.oorsprong.org/websamples.countryinfo/CountryInfoService.wso/ListOfCountryNamesByCode/JSON
 * must be way of getting this direct from the service, but unless I put in this static array it broke?
 */
global $okhub_wrapper_iso_country_data;
$okhub_wrapper_iso_country_data = array('AD'=> 'Andorra', 'AE'=> 'United Arab Emirates', 'AF'=> 'Afghanistan', 'AG'=> 'Antigua & Barbuda', 'AI'=> 'Anguilla', 'AL'=> 'Albania', 'AM'=> 'Armenia', 'AN'=> 'Netherlands Antilles', 'AO'=> 'Angola', 'AQ'=> 'Antarctica', 'AR'=> 'Argentina', 'AS'=> 'American Samoa', 'AT'=> 'Austria', 'AU'=> 'Australia', 'AW'=> 'Aruba', 'AX'=> 'Åland Islands', 'AZ'=> 'Azerbaijan', 'BA'=> 'Bosnia & Herzegovina', 'BB'=> 'Barbados', 'BD'=> 'Bangladesh', 'BE'=> 'Belgium', 'BF'=> 'Burkina Faso', 'BG'=> 'Bulgaria', 'BH'=> 'Bahrain', 'BI'=> 'Burundi', 'BJ'=> 'Benin', 'BM'=> 'Bermuda', 'BN'=> 'Brunei-Darussalam', 'BO'=> 'Bolivia', 'BR'=> 'Brazil', 'BS'=> 'Bahamas', 'BT'=> 'Bhutan', 'BV'=> 'Bouvet Island', 'BW'=> 'Botswana', 'BY'=> 'Belarus', 'BZ'=> 'Belize', 'CA'=> 'Canada', 'CC'=> 'Cocos (Keeling) Islands', 'CD'=> 'Congo, Democratic Republic', 'CF'=> 'Central African Republic', 'CG'=> 'Congo', 'CH'=> 'Switzerland', 'CI'=> 'Côte D\'Ivoire (Ivory Coast)', 'CK'=> 'Cook Islands', 'CL'=> 'Chile', 'CM'=> 'Cameroon', 'CN'=> 'China', 'CO'=> 'Colombia', 'CR'=> 'Costa Rica', 'CS'=> 'Serbia & Montenegro', 'CU'=> 'Cuba', 'CV'=> 'Cape Verde', 'CX'=> 'Chrismas Island', 'CY'=> 'Cyprus', 'CZ'=> 'Czech Republic', 'DE'=> 'Germany', 'DJ'=> 'Djibouti', 'DK'=> 'Denmark', 'DM'=> 'Dominica', 'DO'=> 'Dominican Republic', 'DZ'=> 'Algeria', 'EC'=> 'Ecuador', 'EE'=> 'Estonia', 'EG'=> 'Egypt', 'EH'=> 'Western Sahara', 'ER'=> 'Eritrea', 'ES'=> 'Spain', 'ET'=> 'Ethiopia', 'FI'=> 'Finland', 'FJ'=> 'Fiji', 'FK'=> 'Falkand Islands (Malvinas)', 'FM'=> 'Micronesia (Federa States of)', 'FO'=> 'Faroe Islands', 'FR'=> 'France', 'GA'=> 'Gabon', 'GB'=> 'United Kingdom', 'GD'=> 'Grenada', 'GE'=> 'Georgia', 'GF'=> 'French Guiana', 'GH'=> 'Ghana', 'GI'=> 'Gibraltar', 'GL'=> 'Greenland', 'GM'=> 'Gambia', 'GN'=> 'Guinea', 'GP'=> 'Guadeloupe', 'GQ'=> 'Equatorial Guinea', 'GR'=> 'Greece', 'GS'=> 'South Georgia & South Sandwich Islands', 'GT'=> 'Guatemala', 'GU'=> 'Guam', 'GW'=> 'Guinea-Bissau', 'GY'=> 'Guyana', 'HK'=> 'Hong Kong', 'HM'=> 'Heard Island And McDonald Islands', 'HN'=> 'Honduras', 'HR'=> 'Croatia', 'HT'=> 'Haiti', 'HU'=> 'Hungary', 'ID'=> 'Indonesia', 'IE'=> 'Ireland', 'IL'=> 'Israel', 'IN'=> 'India', 'IO'=> 'British Indian Ocean Territory', 'IQ'=> 'Iraq', 'IR'=> 'Iran', 'IS'=> 'Iceland', 'IT'=> 'Italy', 'JM'=> 'Jamaica', 'JO'=> 'Jordan', 'JP'=> 'Japan', 'KE'=> 'Kenya', 'KG'=> 'Kyrgyzstan', 'KH'=> 'Cambodia', 'KI'=> 'Kiribati', 'KM'=> 'Comoros', 'KN'=> 'St. Kitts & Nevis', 'KP'=> 'North Korea', 'KR'=> 'South Korea', 'KW'=> 'Kuwait', 'KY'=> 'Cayman Islands', 'KZ'=> 'Kazakhstan', 'LA'=> 'Laos', 'LB'=> 'Lebanon', 'LC'=> 'St. Lucia', 'LI'=> 'Liechtenstein', 'LK'=> 'Sri Lanka', 'LR'=> 'Liberia', 'LS'=> 'Lesotho', 'LT'=> 'Lithuania', 'LU'=> 'Luxembourg', 'LV'=> 'Latvia', 'LY'=> 'Libyan Arab Jamahiriya', 'MA'=> 'Morocco', 'MC'=> 'Monaco', 'MD'=> 'Moldova, Republic of', 'MG'=> 'Madagascar', 'MH'=> 'Marshall Islands', 'MK'=> 'Macedonia (former YR)', 'ML'=> 'Mali', 'MM'=> 'Myanmar (Burma)', 'MN'=> 'Mongolia', 'MO'=> 'Macao', 'MP'=> 'Northern Mariana Islands', 'MQ'=> 'Martinique', 'MR'=> 'Mauritania', 'MS'=> 'Montserrat', 'MT'=> 'Malta', 'MU'=> 'Mauritius', 'MV'=> 'Maldives (Maladive Ilands)', 'MW'=> 'Malawi', 'MX'=> 'Mexico', 'MY'=> 'Malaysia', 'MZ'=> 'Mozambique', 'NA'=> 'Namibia', 'NC'=> 'New Caledonia', 'NE'=> 'Niger', 'NF'=> 'Norfolk Island', 'NG'=> 'Nigeria', 'NI'=> 'Nicaragua', 'NL'=> 'Netherlands', 'NO'=> 'Norway', 'NP'=> 'Nepal', 'NR'=> 'Nauru', 'NU'=> 'Niue', 'NZ'=> 'New Zealand', 'OM'=> 'Oman', 'PA'=> 'Panama', 'PE'=> 'Peru', 'PF'=> 'French Polynesia', 'PG'=> 'Papua-New Guinea', 'PH'=> 'Philippines', 'PK'=> 'Pakistan', 'PL'=> 'Poland', 'PM'=> 'Saint Pierre And Micquelon', 'PN'=> 'Pitcairn', 'PR'=> 'Puerto Rico', 'PS'=> 'Palestinian Territory, Occupied', 'PT'=> 'Portugal', 'PW'=> 'Palau', 'PY'=> 'Paraguay', 'QA'=> 'Quatar', 'RE'=> 'Reunion', 'RO'=> 'Romania', 'RU'=> 'Russian Federation', 'RW'=> 'Rwanda', 'SA'=> 'Saudi Arabia', 'SB'=> 'Solomon Islands', 'SC'=> 'Seychelles', 'SD'=> 'Sudan', 'SE'=> 'Sweden', 'SG'=> 'Singapore', 'SH'=> 'Saint Helena', 'SI'=> 'Slovenia', 'SJ'=> 'Svalbard And Jan Mayen', 'SK'=> 'Slovakia', 'SL'=> 'Sierra Leone', 'SM'=> 'San Marino', 'SN'=> 'Senegal', 'SO'=> 'Somalia', 'SR'=> 'Suriname', 'ST'=> 'Sao Tome & Principe', 'SV'=> 'El Salvador', 'SY'=> 'Syrian Arab Republic', 'SZ'=> 'Swaziland', 'TC'=> 'Turks And Caicos Islands', 'TD'=> 'Chad', 'TF'=> 'French Southern Territories', 'TG'=> 'Togo', 'TH'=> 'Thailand', 'TJ'=> 'Tajikistan', 'TK'=> 'Tokelau', 'TL'=> 'Timor-Leste', 'TM'=> 'Turkmenistan', 'TN'=> 'Tunisia', 'TO'=> 'Tonga', 'TR'=> 'Turkey', 'TT'=> 'Trinidad & Tobago', 'TV'=> 'Tuvalu', 'TW'=> 'Taiwan', 'TZ'=> 'Tanzania', 'UA'=> 'Ukraine', 'UG'=> 'Uganda', 'UM'=> 'United States Minor Outlying Islands', 'US'=> 'United States', 'UY'=> 'Uruguay', 'UZ'=> 'Uzbekistan', 'VA'=> 'Vatican City', 'VC'=> 'St. Vincent & Grenadines', 'VE'=> 'Venezuela', 'VG'=> 'Virgin Islands, British', 'VI'=> 'Virgin Islands, U.S.', 'VN'=> 'Vietnam', 'VU'=> 'Vanuatu', 'WF'=> 'Wallis And Futuna', 'WS'=> 'Western Samoa', 'YE'=> 'Yemen', 'YT'=> 'Mayotte', 'ZA'=> 'South Africa', 'ZM'=> 'Zambia', 'ZW'=> 'Zimbabwe');

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
  	/*
  	 * Returns the raw data from any attribute in the API
  	 */
    if (isset($this->hub_data[$field_name])){
    	return $this->hub_data[$field_name];
    }  
    return FALSE; 	
  }
  
  function single_value_to_string($arr){
  	if(is_array($arr)){
	  	if(count($arr) == 1){
	  		if(isset($arr[0])){
	  			return $arr[0];
	  		}
	  	}
  	}
  	return $arr;
  }
  
  public function get_value($field_name, $source_id = FALSE, $language_id = FALSE){
    /*
     * Get a meaningful value for this API attribute using the priority source/language if supplied
     * Attempts to get the varible/array that is contained in the standard [source][language] structure
     * if available or a returns what it finds if that structure is not there and/or uses aternatives
     * if priority source or language not found (i.e. it tries to return something of value!)
     */
  	$exceptions_array = array('sources');
  	global $okhub_wrapper_iso_country_data;
  	$debug_me = FALSE;
  	if($debug_me) { print('GETVALUE:'.$field_name.':'); }
  	$value_obj = $this->get_value_object($field_name);
  	if (isset($this->hub_data['priorities'])) {
  		if(!$source_id){
    		$source_id = $this->hub_data['priorities']['priority_datasource'];
  		}
  		if(!$language_id){
    		$language_id = $this->hub_data['priorities']['priority_language'];
  		}
    } else {
    	if($debug_me) { print('no priorities');}
    	return $value_obj;
    }
  	if ($value_obj){
  		if($debug_me) { print_r($value_obj);}
    	if(is_array($value_obj)){
    		/* first check if theis is an exception -- where we just want the array returned raw e.g. sources */
    		if(in_array($field_name, $exceptions_array)){
    			return $value_obj;
    		}

    		$choosen_obj = FALSE;
    		$fallback_obj = FALSE;
    	    /* See if there is a okhub value */
    		if(isset($value_obj['okhub'])){
    			$choosen_obj = $value_obj['okhub'];
    			if($debug_me) { print('hubfound:');}
    		}
    		/* See if there is a hub value -- NOTE this will be superceeded by okhub */
    		elseif(isset($value_obj['hub'])){
    			$choosen_obj = $value_obj['hub'];
    			if($debug_me) { print('hubfound:');}
    		} else {
	    		/* If not see if there is an item for the choosen priority source */
	    		foreach($value_obj as $source => $lang_obj){
	    			if($debug_me){ print('SOURCE:'.$source); }
	    			if($source == $source_id){
	    				$choosen_obj = $lang_obj;
	    				if($debug_me) { print('objfound:');}
	    			}
	    			$fallback_obj = $lang_obj;
	    		}
	    		/* If not use a fallback */
	    		if(!$choosen_obj){
	    			$choosen_obj = $fallback_obj;
	    		}
	    		if($debug_me) { print_r($choosen_obj);}
    		}
    		/* See if there is an item for the choosen priority language */
    		if($choosen_obj){
	    		$choosen_value = FALSE;
	    		$fallback_value = FALSE;
	    		$fallback_lang_key = FALSE;
	    	   	if(is_array($choosen_obj)){
		    		foreach($choosen_obj as $lang => $value){
		    			if(strtolower($lang) === $language_id){
		    				if($debug_me) { print('langfound:');}
		    				$choosen_value = $value;
		    			}
		    			$fallback_value = $value;
		    			if(array_key_exists(strtoupper($lang), $okhub_wrapper_iso_country_data)){
		    				$fallback_lang_key = $lang;
		    			}
		    		}
	    	   	}
    		   	/* If not use a fallback lang -- unless the key is not a valid lang -- then it must be other type of data */
	    		if(!$choosen_value && $fallback_lang_key){
	    			$choosen_value = $fallback_value;
	    		}
	    		if($choosen_value){
	    			if($debug_me) { print('GOTIT:'); }
	    			/* 
	    			 * this is what we are usually after! 
	    			 * the other stuff is sent back for for fields that
	    			 * dont use the standard [source][language] structure
	    			 * 
	    			 * Note: If it's an Array and only one element then return as string,
	    			 * */
	    			if($debug_me) {print($choosen_value);}
	    			return $this->single_value_to_string($choosen_value);
	    		} else {
	    			if($debug_me) {print_r($choosen_obj);}
	    			return $this->single_value_to_string($choosen_obj);
	    		}
    		} else {
    			if($debug_me) {print_r($value_obj);}
    			return $this->single_value_to_string($value_obj);
    		}
    	} else {
    		if($debug_me) {print_r($value_obj);}
    		return $this->single_value_to_string($value_obj);
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
  /**
   * Constructor.
   */
  function __construct($object) {
    parent::__construct($object);
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