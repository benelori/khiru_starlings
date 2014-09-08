<?php
/**
 * @file
 * khiru_f_general_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function khiru_f_general_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_forum_pattern';
  $strongarm->value = 'forum/[term:name]';
  $export['pathauto_forum_pattern'] = $strongarm;

  return $export;
}
