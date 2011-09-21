<?php
/**
* @file
* Administration page callbacks for the Diigo module.
*/

/**
 * Diigo Module admin_settings
 */
function diigo_admin_settings() {
  $api_key = db_query('SELECT api_key FROM {diigo} WHERE aid = 1')->fetchField();
  $count = db_query('SELECT count FROM {diigo} WHERE aid = 1')->fetchField();
  $form['count'] = array(
    '#title' => t('Count'),
    '#description' => t('Number of bookmarks to retrive'),
    '#type' => 'textfield',
    '#default_value' => $count,
    '#maxlength' => 3,
    '#required' => TRUE,
    '#size' => 3,
    '#weight' => 0,
  );
  $form['api_key'] = array(
    '#title' => t('Diigo API Key'),
    '#description' => t('The API key for your diigo application.'),
    '#type' => 'textfield',
    '#default_value' => $api_key,
    '#maxlength' => 32,
    '#required' => TRUE,
    '#size' => 15,
    '#weight' => 0,
  );
  $form['#submit'][] = 'diigo_admin_settings_submit';
  return system_settings_form($form);
}

function diigo_admin_settings_submit($form, $form_state) {
  $record = new stdClass();
  $record->aid = 1;
  $record->api_key = $form_state['values']['api_key'];
  $record->count = $form_state['values']['count'];
  drupal_write_record('diigo', $record, 'aid');
}

