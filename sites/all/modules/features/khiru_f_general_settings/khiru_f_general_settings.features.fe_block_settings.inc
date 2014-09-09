<?php
/**
 * @file
 * khiru_f_general_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function khiru_f_general_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['paypal_donations-paypal_donations_single'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'paypal_donations_single',
    'module' => 'paypal_donations',
    'node_types' => array(),
    'pages' => 'donate',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'khiru_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'khiru_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
