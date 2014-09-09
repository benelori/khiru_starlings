<?php


function khiru_theme_preprocess_comment(&$variables) {
  if (!empty($variables['comment']->pid)) {
    $comment = comment_load($variables['comment']->pid);
    $wrapper = entity_metadata_wrapper('comment', $comment);
    $variables['in_reply_to'] = $wrapper->comment_body->value()['value'];
  }
}

/**
 * Returns HTML for a textarea form element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #value, #description, #rows, #cols, #required,
 *     #attributes
 *
 * @ingroup themeable
 */
function khiru_theme_textarea($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('form-textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes['class'][] = 'resizable';
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . filter_xss_admin($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}
