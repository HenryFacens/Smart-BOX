# Generated by Django 4.1.6 on 2023-02-09 13:32

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('BOX_SMART', '0002_dadosapi_device_alter_dadosapi_id'),
    ]

    operations = [
        migrations.AlterField(
            model_name='dadosapi',
            name='componente',
            field=models.CharField(blank=True, max_length=50, null=True),
        ),
        migrations.AlterField(
            model_name='dadosapi',
            name='device',
            field=models.CharField(blank=True, max_length=50, null=True),
        ),
    ]
