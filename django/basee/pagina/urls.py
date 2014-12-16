from django.conf.urls import *
from pagina.views import *
#NO USAR ESTA PAGINA SOLO SERVIRIA SI EXISTIESE OTRA APLICACION
urlpatterns = patterns('',

     url(r'^$',archive),
     url(r'^DGmedios/$',DGmedios),

)