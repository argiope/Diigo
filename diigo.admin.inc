<?php
/**
* @file
* Administration page callbacks for the Diigo module.
*/

/**
 * Diigo Module admin_settings
 */
function diigo_admin_settings() {
  $form['api_key'] = array(
    '#title' => t('Diigo API Key'),
    '#description' => t('The API key for your diigo application.'),
    '#type' => 'fieldset',
  );
  $form['count'] = array();
  $form['#submit'][] = 'diigo_admin_settings_submit';
  return system_settings_form($form)
}

function diigo_admin_settings_submit() {

}

