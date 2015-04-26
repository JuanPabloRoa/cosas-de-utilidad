from django.conf.urls import *
from django.contrib import admin

admin.autodiscover()
urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'basee.views.home', name='home'),
     url(r'^$','pagina.views.archive'),
     url(r'^DGmedios/$','pagina.views.DGmedios'),
    url(r'^admin/', include(admin.site.urls)),
    url(r'^Lotus/$','pagina.views.Lotus'),
    url(r'^T4F/$','pagina.views.T4F'),
	#url(r'^$', include(pagina.urls))
)
