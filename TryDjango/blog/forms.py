from django import forms
from .models import Article


class ArticleForm(forms.ModelForm):
    title = forms.CharField(label='Title',
                            widget=forms.TextInput(
                                attrs={
                                    'placeholder': 'Article Title'
                                }
                            )
                            )
    content = forms.CharField(label='Content',
                              widget=forms.Textarea(
                                  attrs={
                                      'rows': 20,
                                      'cols': 200,
                                      'placeholder': 'Complete your article'
                                  }
                              )
                              )
    active = forms.BooleanField(label='Set active?', required=False)
    author = forms.CharField(label='Author',
                             widget=forms.TextInput(
                                 attrs={
                                     'placeholder': 'Author Name'
                                 }
                             )
                             )

    class Meta:
        model = Article
        fields = [
            'title',
            'content',
            'active',
            'author'
        ]
