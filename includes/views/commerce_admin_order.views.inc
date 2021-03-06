<?php

/**
 * Implements hook_views_data()
 */
function commerce_admin_order_views_data() {
  $data = array();

  $data['commerce_admin_order_order'] = array(
    'table' => array(
      'group' => t('Commerce Order'),
      'title' => 'Commerce Admin order',
      'help' => 'Flag indicating whether or not the order was created via the Commerce back-end system',
      'join' => array(
        'commerce_order' => array(
          'left_field' => 'order_id',
          'field' => 'order_id',
          'type' => 'left',
        ),
      ),
    ),
    // Exposing field order_id. If the order_id is in the table, then, as the
    // query uses LEFT JOIN, the result is either an order id or NULL
    'order_id' => array(
      'title' => 'Admin order?',
      'help' => t('Flag indicating if an order was created via the Commerce back-end system'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
      ),
    ),
    'creator_uid' => array(
      'title' => 'Order creator Uid',
      'help' => t("The order creator's ID"),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
    ),
    'created_by_user_name' => array(
      'real field' => 'creator_uid',
      'title' => 'Order created by',
      'help' => t("Name of the user that created the order"),
      'field' => array(
        'handler' => 'commerce_admin_order_handler_field_created_by_user_name',
      ),
    ),
  );

  return $data;
}