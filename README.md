# OKhub API Wrapper

## Introduction

The OKhub API Wrapper attempts to put together a set of useful functions to interact with 
the OKhub API (http://api.okhub.org/) and create PHP objects that represent objects in the API, 
such as Documents, Organisations, Countries and categories.

## OkhubApiWrapper Class
Objects of this class are used to retrieve content in the OKHUB collections  through the OKHUB API.
### Some useful methods
#### Get Sources Options
Get simple array of key=Source ID value=Source Name. (e.g. key=bridge value=BRIDGE)
Usage:
```php
$OkhubApiWrapper->okhubapi_get_sources_options($api_key)
```
#### Get full sources data
Gets an array of full objects of all the sources 
Usage:
```php
$OkhubApiWrapper->okhubapi_get_full_sources_data($api_key)
```
#### Get Source Name from Source ID
get name of source if you send in source code
Usage:
```php
$OkhubApiWrapper->okhubapi_get_source_name_from_id($source_id, $api_key)
```

## OkhubApiObject Class
Objects of this class' inherited classes contain the information of assets (documents and organisations), 
categories (regions and themes) and countries available in the Okhub datasets.
### Some useful methods
#### Get Value Object
Returns the raw data from any attribute in the API.
Usage:
```php
$OkhubApiObject->get_value_object($field_name);
```
#### Get Value
Get a meaningful value for this API attribute using the priority source/language if supplied
Attempts to get the varible/array that is contained in the standard [source][language] structure
if available or a returns what it finds if that structure is not there and/or uses aternatives.
If priority source or language not found/not supplied. I will first try to grab the hub value/object 
and then if not avaible the first availble source version of the supplied field_name failing that it
will return FALSE.
Usage:
```php
$OkhubApiObject->get_value($field_name, $source_id, $language_id)
```
#### Get Value Source Specific
Same as get_value but is Source Specific. i.e. will only return a value if there is one in the 
API object for the source_id supplied or will return FALSE
Usage:
```php
$OkhubApiObject->get_value($field_name, $source_id, $language_id)
```

