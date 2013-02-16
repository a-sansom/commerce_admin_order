This module keeps track of which Commerce orders are created through the 
Commerce back office (the 'Create an order' form at /admin/commerce/orders/add)
and also which user created them.

The module adds a couple of properties, 'is_admin_order' (boolean) and 
'creator_uid' (integer) to the Commerce order entity. The properties can be 
referenced in the following way:

  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $is_admin_order = $order_wrapper->is_admin_order->value();
  $creator_user_id = $order_wrapper->creator_uid->value();

Also defined by the module are some Rules module events. Currently these are:

  'New order created via admin'
  'Order created via admin updated'
  'Order created via admin deleted'
  'Order created via admin payment inserted'
  'Order created via admin payment updated'
  'Order created via admin payment deleted'

The 'is admin order' boolean flag is made available to be displayed in Views in 
the 'Commerce order' group as a field, 'Admin order?'. 

The user id of the user that created the order is also available and a Views 
relationship is defined to the users table so that the name of the user can be 
added to various Views. For example, to add the order creator name to the order
list view:

  - Edit the orders view
  - Relationships -> Add -> Commerce Order: Creator -> Apply
  - Fields -> Add -> User: Name -> Apply
  - Relationships dropdown select 'Order creator' -> Apply
  - Save the view

For orders in the system before this module was installed/enabled, there's no 
way of knowing if they were created via the admin form. This module adds forms 
that lists current orders that are not recorded as being admin orders and lets 
the user mark them as 'admin orders' and vice-versa.

The forms are accessible via tabs on the Commerce orders page:

  /admin/commerce/orders

If you are going to run the module tests, please see the following comment
about the environment you try to run them in:

  http://drupal.org/node/1801928
