<?php

/**
 * @file
 * 
 */

/**
 * 
 */
class commerce_admin_order_handler_field_created_by_user_name extends views_handler_field_user_name {

  function init(&$view, &$data) {
    parent::init($view, $data);

    unset($this->additional_fields['uid']);
    $this->additional_fields['creator_uid'] = 'creator_uid';
  }

  function post_execute(&$values) {
    foreach ($values as $order) {
      // If no uid found in CAOO table, get uid of order first revision
      if (!isset($order->commerce_admin_order_order_creator_uid)) {
        $order->commerce_admin_order_order_creator_uid = commerce_admin_order_order_first_revision_uid($order->order_id);
      }
    }
  }

  function render_link($data, $values) {
    $account = new stdClass();
    $account->uid = $this->get_value($values, 'creator_uid');
    $account->name = commerce_admin_order_username_from_uid($account->uid);

    if (!empty($this->options['link_to_user']) || !empty($this->options['overwrite_anonymous'])) {
      if (!empty($this->options['overwrite_anonymous']) && !$account->uid) {
        return check_plain($this->options['anonymous_text']);
      }
      elseif (!empty($this->options['link_to_user'])) {
        return theme('username', array('account' => $account));
      }
    }

    if (!empty($this->options['format_username'])) {
      return format_username($account);
    }

    return $data;
  }
}