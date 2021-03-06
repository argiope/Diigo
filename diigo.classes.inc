<?php
/**
 * @file
 * contains the DiigoAPI class that accesses the Diigo API
 */
class DiigoAPI {
  public $api_url = 'https://secure.diigo.com/api/v2/bookmarks';
  protected $account = array();
  protected $options = array();
  public $error = '';
  function __construct($apikey, $account, $options) {
    //check to see if there is a $apikey, $account or $options
    $error_free = FALSE;
    $params = '';
    if (is_array($options) && is_array($account)) {
      $error_free = TRUE;
      $this->options = $options;
      $this->account = $account;
    }
    else {
      $this->error = 'Wrong type of variables passed for either $account or $options.';
    }
    if ($error_free == TRUE) {
      $params .= 'key=' . $apikey . '&';
      $params .= 'user=' . $account['user'] . '&';
      foreach ($options as $param => $value) {
        if ($value != '') {
          if ($param != 'tags')
            $params .= $param . '=' . $value . '&';
          else {
            $tags = array();
            foreach ($options['tags'] as $tag) {
              $tags[] = urlencode('"' . $tag . '"');
            }
            $params .= $param . '=' . implode(',', $tags) . '&';
          }
        }
      }
      //unsetting for each variables to prevent weird php stuff
      unset($param);
      unset($value);
      //triming the last &
      $params = rtrim($params, '&');
      $this->params = $params;
    }
  }
  function get_bookmarks() {
    $params = $this->params;
    $options = $this->options;
    $account = $this->account;
    //basic auth info
    $auth = array('Authorization' => 'Basic ' . base64_encode($account['user'] . ':' . $account['pass']));
    //gets bookmarks
    $http_opts = array(
      'headers' => $auth,
      'method' => 'GET',
    );
    $responce = drupal_http_request($this->api_url . '?' . $params, $http_opts);
    if ($responce->code != '200') {
      return dpr($responce);
    }
    else {
      $this->responce = $responce;
      return json_decode($responce->data);
    }
  }
  function post_bookmark() {
    // @todo
    // add Post Bookmark to diigo account function
  }
}

