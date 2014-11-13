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

/**
 * Preprocesses template variables for the topic header template.
 * Overrides advanced_forum equivalent.
 */
function khiru_theme_preprocess_advanced_forum_topic_header(&$variables) {
  // Link to last post in topic.
  $variables['last_post_link'] = khiru_theme_last_post_link($variables['node']);
}

/**
 * Get a link to the last post in a topic. Overrides advanced_forum equivalent.
 *
 * @param $node
 *   Node object
 * @return
 *   Text linking to the last post in a topic.
 */
function khiru_theme_last_post_link($node) {
  $last_comment_id = advanced_forum_last_post_in_topic($node->nid);
  // Return empty link if post doesn't have comments.
  if (empty($last_comment_id))
    return '';

  $last_page = advanced_forum_get_last_page($node);

  if ($last_page > 0)
    $query = array('page' => $last_page);

  $options = array(
    'html' => TRUE,
    'query' => empty($query) ? array() : $query,
    'fragment' => "comment-$last_comment_id",
  );

  return theme('advanced_forum_l', array(
    'text' => t('Go to bottom'),
    'path' => "node/$node->nid",
    'options' => $options,
    'button_class' => 'large'
  ));
}
