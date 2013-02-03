<?php

/**
 * Implements hook_default_rules_configuration()
 */
function commerce_admin_order_default_rules_configuration() {
  $rules = array();

  // Order created
  $rule = rules_reaction_rule();
  $rule->label = t('Display Commerce Admin order created message');
  $rule->active = TRUE;

  $rule
  ->event('commerce_admin_order_order_created')
  ->action(
    'drupal_message',
    array(
      'message' => t('Admin order created.'),
    )
  );

  $rules['commerce_admin_order_order_created_message'] = $rule;

  // Order updated
  $rule = rules_reaction_rule();
  $rule->label = t('Display Commerce Admin order updated message');
  $rule->active = TRUE;

  $rule
    ->event('commerce_admin_order_order_updated')
    ->action(
      'drupal_message',
      array(
        'message' => t('Admin order updated.'),
      )
  );

  $rules['commerce_admin_order_order_updated_message'] = $rule;

  // Order deleted
  $rule = rules_reaction_rule();
  $rule->label = t('Display Commerce Admin order deleted message');
  $rule->active = TRUE;

  $rule
    ->event('commerce_admin_order_order_deleted')
    ->action(
      'drupal_message',
      array(
        'message' => t('Admin order deleted.'),
      )
  );

  $rules['commerce_admin_order_order_deleted_message'] = $rule;

  // Order payment transaction inserted/created
  $rule = rules_reaction_rule();
  $rule->label = t('Display Commerce Admin order payment transaction inserted message');
  $rule->active = TRUE;

  $rule
    ->event('commerce_admin_order_payment_transaction_inserted')
    ->action(
      'drupal_message',
      array(
        'message' => t('Admin order payment transaction inserted.'),
      )
  );

  $rules['commerce_admin_order_payment_transaction_inserted_message'] = $rule;

  // Order payment transaction deleted
  $rule = rules_reaction_rule();
  $rule->label = t('Display Commerce Admin order payment transaction updated message');
  $rule->active = TRUE;

  $rule
    ->event('commerce_admin_order_payment_transaction_updated')
    ->action(
      'drupal_message',
      array(
        'message' => t('Admin order payment transaction upated.'),
      )
  );

  $rules['commerce_admin_order_payment_transaction_upated_message'] = $rule;

  // Order payment transaction deleted
  $rule = rules_reaction_rule();
  $rule->label = t('Display Commerce Admin order payment transaction deleted message');
  $rule->active = TRUE;

  $rule
    ->event('commerce_admin_order_payment_transaction_deleted')
    ->action(
      'drupal_message',
      array(
        'message' => t('Admin order payment transaction deleted.'),
      )
  );

  $rules['commerce_admin_order_payment_transaction_deleted_message'] = $rule;

  return $rules;
}