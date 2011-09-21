<?php
/**
 * @file
 * Has the user configuration settings.
 */
function diigo_user_settings() {
  global $user;
  $id = db_query('SELECT id FROM {diigo_users} WHERE uid = :uid',
  array('uid' => $user->uid))->fetchField();
  $id = ($id)? $id : FALSE;
  $query = db_select('diigo_users', 'd');
  $query->condition('uid', $user->uid)
  ->fields('d', array('username', 'pass', 'list', 'sort', 'tags', 'filter'));
  $results = $query->execute();
  $options = '';
  foreach ($results as $result) {
    $options = $result;
  }
  if (!$options) {
    $options = new stdClass();
    $options->username = '';
    $options->pass = '';
    $options->list = '';
    $options->sort = 0;
    $options->tags = '';
    $options->filter = 'public';
  }
  $form['username'] = array(
    '#title' => t('Diigo Username'),
    '#description' => t('The username for your Diigo account.'),
    '#type' => 'textfield',
    '#default_value' => $options->username,
    '#maxlength' => 32,
    '#required' => TRUE,
    '#size' => 15,
    '#weight' => -10,
  );
  $form['pass'] = array(
    '#title' => t('Diigo Password'),
    '#description' => t('The password for your Diigo account.'),
    '#type' => 'password',
    '#default_value' => $options->pass,
    '#maxlength' => 32,
    '#required' => TRUE,
    '#size' => 15,
    '#weight' => -9,
  );
  $form['sort'] = array(
    '#title' => t('Sort Options'),
    '#description' => t('Sort options for diigo bookmarks.'),
    '#type' => 'radios',
    '#options' => array(
      t('Sort by bookmark creation time.'),
      t('Sort by bookmark update time.'),
      t('Sort by bookmark popularity.'),
    ),
    '#default_value' => $options->sort,
    '#weight' => 0,
    '#required' => TRUE,
  );
  $form['tags'] = array(
    '#title' => t('Tags'),
    '#description' => t('Specify the tags of the boomkmarks separated by commas (php,ruby,etc.).'),
    '#type' => 'textfield',
    '#default_value' => $options->tags,
    '#maxlength' => 32,
    '#size' => 15,
    '#required' => FALSE,
    '#weight' => 0,
  );
  $form['filter'] = array(
    '#title' => t('Filter'),
    '#description' => t('The username for your Diigo account.'),
    '#type' => 'radios',
    '#options' => array(
      'public' => t('Display only public bookmarks.'),
      'private' => t('Display only private bookmarks.'),
      'all' => t('Display both public and private bookmarks.'),
    ),
    '#default_value' => $options->filter,
    '#required' => TRUE,
    '#weight' => 0,
  );
  $form['list'] = array(
    '#title' => t('List'),
    '#description' => t('Spicify which list you want your bookmarks to come from.'),
    '#type' => 'textfield',
    '#default_value' => $options->list,
    '#maxlength' => 32,
    '#required' => FALSE,
    '#size' => 15,
    '#weight' => 0,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $user->uid,
  );
  $form['id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );
  $form['#validate'][] = 'diigo_user_settings_validate';
  $form['#submit'][] = 'diigo_user_settings_submit';
  return $form;
}
function diigo_user_settings_submit($form, &$form_state) {
  $record = new stdClass();
  $record->username = check_plain($form_state['values']['username']);
  $record->pass = check_plain($form_state['values']['pass']);
  $record->list = check_plain($form_state['values']['list']);
  $record->uid = $form_state['values']['uid'];
  $record->filter = check_plain($form_state['values']['filter']);
  $record->sort = check_plain($form_state['values']['sort']);
  $record->tags = check_plain($form_state['values']['tags']);
  $record->tags = preg_replace('/&amp;/', '&', $record->tags);
  if ($form_state['values']['id']) {
    $record->id = $form_state['values']['id'];
    drupal_write_record('diigo_users', $record, 'id');
  }
  else {
    drupal_write_record('diigo_users', $record);
  }
  $form_state['redirect'] = 'user';
}
function diigo_user_settings_validate($form, &$form_state) {
  //
}

