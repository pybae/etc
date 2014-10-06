from django import forms
from rango.models import Category
from rango.models import Page

class CategoryForm(forms.ModelForm):
    """docstring for CategoryForm"""
    name = forms.CharField(max_length=128, help_text="Please enter the category name.")
    views = forms.IntegerField(widget=forms.HiddenInput(), initial=0)
    likes = forms.IntegerField(widget=forms.HiddenInput(), initial=0)

    class Meta:
        """docstring for Meta"""
        model = Category

class PageForm(forms.ModelForm):
    """docstring for PageForm"""
    title = forms.CharField(max_length=128, help_text="Please enter the title of the page.")
    url = forms.URLField(max_length=200, help_text="Please enter the URL of the page.")
    views = forms.IntegerField(widget=forms.HiddenInput(), initial=0)

    class Meta:
        """docstring for Page"""
        model = Page
        fields = ('title', 'url', 'views')


