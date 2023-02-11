from django.urls import path
from . import views

urlpatterns = [
    path("API/DATA/",views.receive_data, name="json" )
]


