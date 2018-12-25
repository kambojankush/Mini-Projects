from django.shortcuts import render, get_object_or_404
from django.urls import reverse
from .forms import ArticleForm
from .models import Article
from django.views.generic import CreateView, UpdateView, DeleteView


# Create your views here.
class ArticleCreateView(CreateView):
    template_name = 'article_create.html'
    queryset = Article.objects.all()
    form_class = ArticleForm

    def form_valid(self, form):
        # print(form.cleaned_data)
        return super().form_valid(form)


class ArticleUpdateView(UpdateView):
    template_name = 'article_update.html'
    form_class = ArticleForm

    def get_object(self, queryset=None):
        id_ = self.kwargs.get('id')
        return get_object_or_404(Article, id=id_)

    def form_valid(self, form):
        # print(form.cleaned_data)
        return super().form_valid(form)


class ArticleDeleteView(DeleteView):
    template_name = 'article_delete.html'

    def get_object(self, queryset=None):
        print(self.kwargs)
        id_ = self.kwargs.get('id')
        return Article.objects.get(id=id_)

    def get_success_url(self):
        return reverse('blog:article-list')


def article_detail_view(request, id):
    obj = get_object_or_404(Article, id=id)
    context = {
        'object': obj
    }
    return render(request, 'article_detail.html', context)


def article_list_view(request):
    queryset = Article.objects.all()
    context = {
        'object_list': queryset
    }
    return render(request, 'article_list.html', context)