This module keeps track of which Commerce orders are created through the 
Commerce back office (the 'Create an order' form at /admin/commerce/orders/add)
by storing order ids in a database table, commerce_admin_order_order.

The module adds a boolean property, is_admin_order, to the Commerce order 
entity. The property can be referenced in the following way:

  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $is_admin_order = $order_wrapper->is_admin_order->value();

Also defined by the module are some Rules module events. Currently these are:

  'New order created via admin'
  'Order created via admin updated'
  'Order created via admin deleted'

For existing orders, as there's no way of knowing if they were created via the
admin form, the module adds a form that lists current orders that are not
recorded as being admin orders and lets the user mark them as 'admin orders'.
Submitting the form adds the orders selected ids to the
commerce_admin_order_order database table. The form is available at:

  /admin/commerce/commerce_admin_order