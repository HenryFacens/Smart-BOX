from django.db import models
from GeneralSystem.models import Device

class DadosAPI(models.Model):
    created         = models.DateTimeField(auto_now_add=True)
    updated_at      = models.DateTimeField(auto_now=True)

    # device          = models.ForeignKey(Device, on_delete=models.CASCADE, blank=True, null=True)
    device          = models.CharField(max_length=50,blank=True,null=True)
    componente      = models.CharField(max_length=50,blank=True,null=True)
    valor           = models.DecimalField(max_digits=5,decimal_places=3)
    def __str__(self):
        return str(self.id)