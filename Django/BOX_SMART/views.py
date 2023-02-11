from django.shortcuts import render
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from .models import DadosAPI 
from GeneralSystem.models import Device

# @csrf_exempt
@csrf_exempt
def receive_data(request):
    if request.method == 'POST':
        data = request.POST

        device          = data.get('device')
        componente      = data.get('cmp')
        valor           = data.get('value')

        # try:
            # device          = Device.objects.filter(serial=device) or 0

        dados           = DadosAPI(device=device,componente=componente,valor=valor)
        dados.save()
        return JsonResponse({'Dados recebidos com sucesso!': True})
    else:
        return JsonResponse({'erro': "erro"})
device = Device.objects.get(serial=request.GET.get("device"))