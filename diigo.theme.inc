<?php
/**
 * Implmentation of hook_theme()
 */
function diigo_theme() {
  return array(
    'forums' => array(
      'template' => 'diigo',
      'variables' => array(
        'diigo_url' => NULL,
        'diigo_url_domain' => NULL,
        'updated_at' => NULL,
        'created_at' => NULL,
        'diigo_user' => NULL,
        'diigo_title' => NULL,
        'diigo_desc' => NULL,
        'diigo_bookmark_number' => NULL,
        'diigo_zebra' => NULL,
        ),
    ),
//...
  );
}

/**
 * template_preprocess_hook()
 */

function template_preprocess_diigo(&$variables){

}

