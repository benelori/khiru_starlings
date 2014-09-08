<?php


function khiru_theme_preprocess_comment(&$variables) {
  if (!empty($variables['comment']->pid)) {
    $comment = comment_load($variables['comment']->pid);
    $wrapper = entity_metadata_wrapper('comment', $comment);
    $variables['in_reply_to'] = $wrapper->comment_body->value()['value'];
  }
}