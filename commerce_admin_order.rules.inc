<?php
/**
 * Implements of hook_rules_event_info()
 */
function commerce_admin_order_rules_event_info() {
  return array(
    'commerce_admin_order_order_updated' => array(
      'label' => t('Order created via admin updated'),
      'group' => 'Commerce Admin order',
      'module' => 'commerce_admin_order',
      'variables' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('The updated order')
        ),
      ),
    ),
    'commerce_admin_order_order_created' => array(
      'label' => t('New order created via admin'),
      'group' => 'Commerce Admin order',
      'module' => 'commerce_admin_order',
      'variables' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('The newly created order')
        ),
      ),
    ),
    'commerce_admin_order_order_deleted' => array(
      'label' => t('Order created via admin deleted'),
      'group' => 'Commerce Admin order',
      'module' => 'commerce_admin_order',
      'variables' => array(
        'order_id' => array(
          'type' => 'integer',
          'label' => t('The deleted orders id')
        ),
      ),
    ),
  );
}