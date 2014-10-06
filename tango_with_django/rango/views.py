"""
The primary view for Rango
"""

from django.http import HttpResponse
from django.template import RequestContext
from django.shortcuts import render_to_response

from rango.models import Category


def index(request):
    context = RequestContext(request)

    category_list = Category.objects.order_by('-likes')[:5]
    context_dict = {'categories': category_list}

    return render_to_response('rango/index.html', context_dict, context)
    
def about(request):
    """
    Returns the about page
    """
    context = RequestContext(request)
    context_dict = {}

    return render_to_response('rango/about.html', context_dict, context)
