<?php

/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_install_tasks().
 */
function khiru_profile_install_tasks($install_state) {
  // List of tasks which should run while the site install.
  $tasks = array(
    'khiru_profile_revert_features' => array(
      'display_name' => st('Revert Features'),
      'type' => 'normal',
    ),
  );
  return $tasks;
}

/**
 * Revert features on install.
 */
function khiru_profile_revert_features() {
  // Feature revert on site install.
  $features = array(
    'khiru_f_block_settings' => array('fe_block_settings'),
    'khiru_f_general_settings' => array('variable'),
  );
  khiru_profile_features_revert($features);
}

/**
 * Revert components of the given features.
 */
function khiru_profile_features_revert($modules) {
  $items = array();
  // Process modules.
  foreach ($modules as $module => $components_needed) {
    if (($feature = feature_load($module, TRUE)) && module_exists($module)) {
      $components = array();
      // Forcefully revert all components of a feature.
      foreach (array_keys($feature->info['features']) as $component) {
        if (features_hook($component, 'features_revert')) {
          $components[] = $component;
        }
      }

      if (!empty($components_needed) && is_array($components_needed)) {
        $components = array_intersect($components, $components_needed);
      }
      if (!empty($components)) {
        $items[$module] = $components;
      }
    }
  }

  if (!empty($items)) {
    features_revert($items);
  }
}

/**
 * Sets default timezone.
 */
function khiru_profile_set_default_timezone() {
  variable_set('date_default_timezone', 'Europe/Paris');
}
