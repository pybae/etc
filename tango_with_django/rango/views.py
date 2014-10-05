"""
The primary view for Rango
"""

from django.http import HttpResponse
from django.template import RequestContext
from django.shortcuts import render_to_response

def index(request):
    context = RequestContext(request)
    context_dict = {'boldmessage': "I am bold font from the context"}

    return render_to_response('rango/index.html', context_dict, context)
    
def about(request):
    """
    Returns the about page
    """
    context = RequestContext(request)
    context_dict = {}

    return render_to_response('rango/about.html', context_dict, context)
