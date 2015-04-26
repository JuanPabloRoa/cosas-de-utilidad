from django.shortcuts import render
from django.template import loader, Context
from django.http import HttpResponse 
from pagina.models import Persona
# Create your views here.

def archive(request):
	personas = Persona.objects.all()
	mi_template=loader.get_template("principal.html")
	mi_contexto = Context({'personas':personas})
	return HttpResponse(mi_template.render(mi_contexto))

def DGmedios(request):
	personas = Persona.objects.all()
	mi_template=loader.get_template("DGmedios.html")
	mi_contexto = Context({'personas':personas})
	return HttpResponse(mi_template.render(mi_contexto))

def Lotus(request):
	personas = Persona.objects.all()
	mi_template=loader.get_template("Lotus.html")
	mi_contexto = Context({'personas':personas})
	return HttpResponse(mi_template.render(mi_contexto))

def T4F(request):
	personas = Persona.objects.all()
	mi_template=loader.get_template("T4F.html")
	mi_contexto = Context({'personas':personas})
	return HttpResponse(mi_template.render(mi_contexto))