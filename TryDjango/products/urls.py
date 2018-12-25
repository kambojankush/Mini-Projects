from django.urls import path
from .views import (
    product_list_view,
    product_delete_view,
    product_create_view,
    product_detailed_view
)

app_name = 'products'
urlpatterns = [
    path('', product_list_view, name='product-list'),
    path('create/', product_create_view, name='product-create'),
    path('<int:id>/', product_detailed_view, name='product-detail'),
    path('<int:id>/delete/', product_delete_view, name='product-delete'),
]
