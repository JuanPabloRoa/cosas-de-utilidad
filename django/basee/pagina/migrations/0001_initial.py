# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Persona',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('nombre_persona', models.CharField(max_length=60)),
                ('fecha_nacimiento', models.DateTimeField()),
            ],
            options={
            },
            bases=(models.Model,),
        ),
    ]
