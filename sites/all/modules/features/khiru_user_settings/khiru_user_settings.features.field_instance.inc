<?php
/**
 * @file
 * khiru_user_settings.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function khiru_user_settings_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_post_preset_lower'
  $field_instances['user-user-field_post_preset_lower'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a post preset that appears below your posts.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_post_preset_lower',
    'label' => 'Post Preset Lower',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'user-user-field_post_preset_upper'
  $field_instances['user-user-field_post_preset_upper'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a preset to all your posts.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_post_preset_upper',
    'label' => 'Post Preset Upper',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'user-user-field_virtual_currency'
  $field_instances['user-user-field_virtual_currency'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 10,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_virtual_currency',
    'label' => 'Virtual Currency',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a post preset that appears below your posts.');
  t('Add a preset to all your posts.');
  t('Post Preset Lower');
  t('Post Preset Upper');
  t('Virtual Currency');

  return $field_instances;
}
