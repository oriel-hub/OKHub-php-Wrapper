<?php

/**
 * Wordpress-specific variables and functions.
 *
 */

global $okhubapi_errors;
$okhubapi_errors = array();

// Call the URL.
function okhubapi_get_data($url) {
  $response = wp_remote_get($url, array('timeout' => 60));
  if (is_wp_error($response)) {
    $data = $response->get_error_message();
  }
  else {
    $data = json_decode($response['body'], true);
  }
  return $data;
}

//------------------------------ Error processing --------------------------------

// Register a new error or notification.
function okhubapi_register_error($component, $message, $function, $error_code, $verbose = TRUE) {
  global $okhubapi_errors;
  $text_message = $message;
  if ($verbose) {
    if ($component) {
      $text_message = $component . ' reported: ' . $text_message;
    }
    if ($function) {
      $text_message .= ' In: ' . $function;
    }
  }
  if (isset($okhubapi_errors[$error_code])) {
    $okhubapi_errors[$error_code]->add($error_code, $text_message); 
  }
  else {
    $okhubapi_errors[$error_code] = new WP_Error($error_code, $text_message);
  }
}

//------------------------------ Options handling --------------------------------

// Set the value of a parameter.
function okhubapi_variable_set($group, $variable_name, $value) {
  $options_name = $group . '_options';
  if ($options = get_option($options_name)) {
    $options[$variable_name] = $value;
    update_option($options_name, $options);
  }
  else {
    $options[$variable_name] = $value;
    add_option($options_name, $options);
  }
}

// Retrieve the value of a saved parameter
function okhubapi_variable_get($group, $variable_name, $default = '') {
  $value = $default;
  $options_name = $group . '_options';
  $options = get_option($options_name);
  if (isset($options[$variable_name])) {
    $value = $options[$variable_name];
  }
  return $value;
}




