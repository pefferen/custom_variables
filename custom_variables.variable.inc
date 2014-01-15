<?php

/**
 * Implement hook_variable_info()
 */
function custom_variables_variable_info($options) {
  $variable['custom_variables_variable'] = array(
    'title' => t('My variable'),
    );

  $variable['custom_variables_url1_[url_part]'] = array(
    'title' => t('My Url'),
    'type' => 'url_full',
    );

  $variable['custom_variables_name'] = array(
    'title' => t('Name', array(), $options),
    'descriptiokn' => t('Enter the name.', array(), $options),
    'type' => 'string',
    'access' => 'administer menus',
    'token' => TRUE,
    );

  $variable['custom_variables_name'] = array(
    'title' => t('Name', array(), $options),
    'description' => t('Enter your name, please.', array(), $options),
    'type' => 'string',
    'default' => t('Drupal user', array(), $options),
  );

  $variable['custom_variables_mail_[mail_part]'] = array(
    'title' => t('Mail'),
    'type' => 'mail_text',
    // This type will spawn into two real variables: mymodule_mail_subject, mymodule_mail_body
    // Everything, included the form elements, will be handled automatically
  );

$variable['custom_variables_urls_[url_part]'] = array(
    'title' => t('Urls'),
    'type' => 'custom_url_full',
    // This type will spawn into two real variables: mymodule_mail_subject, mymodule_mail_body
    // Everything, included the form elements, will be handled automatically
  );
  return $variable;
}

/**
 * Implements hook_variable_type()
 */
function custom_variables_variable_type() {
  $type['custom_url_full'] = array(
    'title' => t('Url full'),
    'multiple' => array('title' => t('Title'), 'url' => t('Url')),
    'build callback' => 'variable_build_url_full',
    'localize' => TRUE,
    'type' => 'multiple',
  );
  // kpr($type);
  $type['url_part'] = array(
    'title' => t('Url parts'),
    'options' => array('title' => t('Title'), 'url' => t('Url')),
  );
  return $type;
}

function variable_build_url_full($variable, $options = array()) {
  $name = str_replace('[url_part]', '', $variable['name']);
  // For Url full, children have different types
  dpm(get_defined_vars());
  $variable['children'][$name . 'title']['type'] = 'string';
  $variable['children'][$name . 'url']['type'] = 'string';
  $variable = variable_build_multiple($variable, $options);
  return $variable;
}

