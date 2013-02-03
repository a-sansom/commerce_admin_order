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
    'commerce_admin_order_payment_transaction_updated' => array(
      'label' => t('Order created via admin payment updated'),
      'group' => 'Commerce Admin order',
      'module' => 'commerce_admin_order',
      'variables' => array(
        'commerce_payment_transaction' => array(
          'type' => 'commerce_payment_transaction',
          'label' => t('The updated payment transaction')
        ),
      ),
    ),
    'commerce_admin_order_payment_transaction_inserted' => array(
      'label' => t('Order created via admin payment inserted'),
      'group' => 'Commerce Admin order',
      'module' => 'commerce_admin_order',
      'variables' => array(
        'commerce_payment_transaction' => array(
          'type' => 'commerce_payment_transaction',
          'label' => t('The inserted payment transaction')
        ),
      ),
    ),
    'commerce_admin_order_payment_transaction_deleted' => array(
      'label' => t('Order created via admin payment deleted'),
      'group' => 'Commerce Admin order',
      'module' => 'commerce_admin_order',
      'variables' => array(
        'commerce_payment_transaction' => array(
          'type' => 'commerce_payment_transaction',
          'label' => t('The deleted payment transaction')
        ),
      ),
    ),
  );
}