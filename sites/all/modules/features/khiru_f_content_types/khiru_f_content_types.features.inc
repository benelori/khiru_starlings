<?php
/**
 * @file
 * khiru_f_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function khiru_f_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function khiru_f_content_types_node_info() {
  $items = array(
    'paypal_donation_page' => array(
      'name' => t('PayPal Donation Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
