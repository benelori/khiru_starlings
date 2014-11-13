<?php
/**
 * @file
 * khiru_f_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function khiru_f_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit_user_virtual_currency'.
  $permissions['edit_user_virtual_currency'] = array(
    'name' => 'edit_user_virtual_currency',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'khiru_general',
  );

  return $permissions;
}
