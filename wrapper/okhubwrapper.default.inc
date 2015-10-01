<?php

/**
* OKHUB Plugins default parameters.
*
* Sets default values to the API URL, documentation URL, cache time, etc.
*/
//error_reporting(E_ERROR | E_PARSE);
// Cache parameters for API responses.
define('OKHUB_API_USE_CACHE', FALSE);
define('OKHUB_API_CACHE_REQUESTS', 'okhubapi_cache');
define('OKHUB_API_DEFAULT_CACHE_TIME', 86400); //One day
define('OKHUB_API_CACHE_DIR', 'cache');

// Error levels to display and format of error messages
define('OKHUB_API_SHOW_ERROR_CODES', 'error,warning,notification');
define('OKHUB_API_HTML_ERRORS', TRUE);

// Default API parameters
define('OKHUB_API_DEFAULT_DATASET', 'hub');
define('OKHUB_API_NUM_ITEMS', 20); 
define('OKHUB_API_DEFAULT_FORMAT', 'full');
define('OKHUB_API_DEFAULT_TYPE_REQUEST', 'search');
define('OKHUB_API_AGE_NEW_ASSETS', 0);

// Parameters that shouldn't be changed by the API users, in general
//define('OKHUB_API_URL', 'http://api.ids.ac.uk/openapi/');
define('OKHUB_API_URL', 'http://api.okhub.org/v1/');
define('OKHUB_API_HOME_URL', 'http://www.okhub.org/');
//http://api.okhub.org/v1
define('OKHUB_API_KEY_URL', 'http://www.okhub.org/accounts/register/');
define('OKHUB_API_DOCUMENTATION_URL', 'http://api.ids.ac.uk/docs/');
define('OKHUB_API_SEARCH_FIELDS_URL', 'http://api.ids.ac.uk/docs/functions/search/');
define('OKHUB_API_MAX_NUM_ITEMS', 500); // OKHUB_API_MAX_NUM_ITEMS is the max. page size allowed by the API (http://api.ids.ac.uk/docs/)
define('OKHUB_API_KEY_PAR', '_token_guid');
define('OKHUB_API_CSS_OBJECT', 'okhub-object');
define('OKHUB_API_PREFIX', 'OKHUB');

define('OKHUB_API_ISO_CODE_DATA_URL', 'http://www.oorsprong.org/websamples.countryinfo/CountryInfoService.wso/ListOfCountryNamesByCode/JSON');

/*
 * Atribute/Field name constants (whilst API is still in flux)
 */

/* Hub Attributes from API */
define('OKHUB_API_FN_TITLE', 'title');
define('OKHUB_API_FN_ITEM_ID', 'item_id');/* Joe seems to have changed from hub_item_id */
define('OKHUB_API_FN_ITEM_TYPE', 'hub_item_type');
define('OKHUB_API_FN_DOCUMENT_TYPE', 'hub_document_type');
define('OKHUB_API_FN_METADATA_LANGAUAGES', 'metadata_languages');
define('OKHUB_API_FN_METADATA_URL', 'metadata_url');
define('OKHUB_API_FN_ORGANISATION', 'hub_organisation');
define('OKHUB_API_FN_REGION', 'hub_region');
define('OKHUB_API_FN_SUBJECT', 'hub_subject');
define('OKHUB_API_FN_THEME', 'hub_theme');
define('OKHUB_API_FN_TIMESTAMP', 'hub_timestamp');
define('OKHUB_API_FN_DESCRIPTION', 'description');
define('OKHUB_API_FN_NAME', 'name');
define('OKHUB_API_FN_SOURCE_CODE', 'code');
define('OKHUB_API_FN_SOURCES', 'sources');
define('OKHUB_API_FN_WEBSITE_URL', 'website_url');
define('OKHUB_API_FN_URLS', 'urls');
define('OKHUB_API_FN_DATE_CREATED', 'date_created');
define('OKHUB_API_FN_DATE_UPDATED', 'date_updated');
define('OKHUB_API_FN_SITE', 'hub');
define('OKHUB_API_FN_ARCHIVED', 'archived');

define('OKHUB_API_FN_THEME_DATA', 'theme_array');
define('OKHUB_API_FN_SUBJECT_DATA', 'subject_array');

/* 
 * Old Eldis/Bridge attibutes that need Hub attribute equivilants 
 * -to work with the Drupal module the structure of these attributes (the array)
 * needs to be the same, assume it will not be quite the same so the Drupal module
 * will need to be updated. 
 * Use attributes below with caution and there are more prone to change structure as well as name    
 * */
define('OKHUB_API_FN_REGION_DATA', 'category_region_array');
define('OKHUB_API_FN_COUNTRY_DATA', 'country_focus_array');









