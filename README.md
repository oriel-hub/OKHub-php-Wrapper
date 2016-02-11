# OKhub API Wrapper

## Introduction

The OKhub API Wrapper attempts to put together a set of useful functions to interact with 
the [OKhub API](http://api.okhub.org) and create PHP objects that represent objects in the API, 
such as Documents, Organisations, Countries and categories.

## OkhubApiWrapper Class
Objects of this class are used to retrieve content in the OKhub collections  through the OKhub API.
### Some useful methods
#### Search, Get, Get All & Count
Calls to the OKhub API. Exampes can be found in the [OKhub API Documentation](http://developer.okhub.org/hub-api-documentation/api-explorer/).
```php
$OkhubApiWrapper->search($object_type, $site, $api_key, $format = 'full', $num_requested = 0, $age_results = 0, $start_offset = 0, $params = array(), $extra_fields = array(), $priorities = FALSE);

$OkhubApiWrapper->get($object_type, $site, $api_key, $format = 'full', $object_id, $priorities = FALSE) ;

$OkhubApiWrapper->getAll($object_type, $site, $api_key, $format = 'full', $priorities = FALSE);

$OkhubApiWrapper->count($object_type, $site, $api_key, $count_category, $age_results = 0, $params=array());

```
#### Make Request
All of the above methods use this method to build the URL to make a call to the API The wrapper object OkhubApiWrapper have an attribute $OkhubApiWrapper->request which is an instance of class OkhubApiRequest. The methods below makes the request to the API through the OkhubApiRequest class and returns an instance of the OkhubApiResponse class.
```php
$OkhubApiWrapper->makeRequest()
```
#### Get Sources List
A method that can be used to return all the Sources in a simple array of key => Source Code value => Source Name. (e.g. ['bridge'] => 'BRIDGE').
```php
$OkhubApiWrapper->okhubapi_get_sources_options($api_key)
```
#### Get full sources data
Gets an array of full objects of all the sources.
```php
$OkhubApiWrapper->okhubapi_get_full_sources_data($api_key)
```
#### Get Source Name from Source Code
Get Source Name if you pass in a Source Code. (e.g. $OkhubApiWrapper->okhubapi_get_source_name_from_id(bridge) returns BRIDGE).
```php
$OkhubApiWrapper->okhubapi_get_source_name_from_id($source_id, $api_key)
```

## OkhubApiObject Class
Objects of this class' inherited classes contain the information of assets (documents and organisations), 
categories (regions and themes) and countries available in the Okhub datasets.
### Some useful methods
#### Get Value Object
Returns the raw data from any field in the API.
```php
$OkhubApiObject->get_value_object($field_name);
```
#### Get Value
Get a meaningful value for this API field using the priority source/language if supplied
Attempts to get the varible/array that is contained in the standard [source][language] structure
if available or a returns what it finds if that structure is not there and/or uses aternatives.
If priority source or language not found/not supplied. I will first try to grab the hub value/object 
and then if not avaible the first availble source version of the supplied field_name failing that it
will return FALSE.
```php
$OkhubApiObject->get_value($field_name, $source_id, $language_id)
```
#### Get Value Source Specific
Same as get_value but is Source Specific. i.e. will only return a value if there is one in the 
API object for the source_id supplied or will return FALSE.
```php
$OkhubApiObject->get_value($field_name, $source_id, $language_id)
```

