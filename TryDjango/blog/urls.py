from django.urls import path
from .views import (
    article_detail_view,
    article_list_view,
    ArticleCreateView,
    ArticleUpdateView,
    ArticleDeleteView,
)

app_name = 'blog'
urlpatterns = [
    path('', article_list_view, name='article-list'),
    path('<int:id>/', article_detail_view, name='article-detail'),
    path('create/', ArticleCreateView.as_view(), name='article-create'),
    path('<int:id>/update/', ArticleUpdateView.as_view(), name='article-update'),
    path('<int:id>/delete/', ArticleDeleteView.as_view(), name='article-delete'),
]
