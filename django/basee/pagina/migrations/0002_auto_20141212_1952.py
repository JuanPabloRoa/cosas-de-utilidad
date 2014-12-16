# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('pagina', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Artista',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('nombre_artista', models.CharField(max_length=60)),
                ('genero_musical', models.CharField(max_length=60)),
            ],
            options={
                'verbose_name_plural': 'Nombre Artista',
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Asisten',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Contiene',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Contrata',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('id_artista', models.ForeignKey(to='pagina.Artista')),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Cuenta',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('nombre_cuenta', models.CharField(max_length=60)),
                ('twitter', models.CharField(max_length=60)),
                ('fecha_creacion', models.DateTimeField()),
            ],
            options={
                'verbose_name_plural': 'Nombre Cuenta',
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Cuenta_Persona',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('id_cuenta', models.ForeignKey(to='pagina.Cuenta')),
                ('id_persona', models.ForeignKey(to='pagina.Persona')),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Evento',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('nombre_evento', models.CharField(max_length=60)),
            ],
            options={
                'verbose_name_plural': 'Nombre Evento',
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Hashtag',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('contenido_hashtag', models.CharField(max_length=60)),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Lugar',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('nombre_lugar', models.CharField(max_length=60)),
                ('direccion', models.CharField(max_length=60)),
            ],
            options={
                'verbose_name_plural': 'Nombre Lugar',
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Pais',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('nombre_pais', models.CharField(max_length=60)),
            ],
            options={
                'verbose_name_plural': 'Nombre Pais',
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Persona_Pais',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('id_pais', models.ForeignKey(to='pagina.Pais')),
                ('id_persona', models.ForeignKey(to='pagina.Persona')),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Productora',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('nombre_productora', models.CharField(max_length=60)),
                ('fecha_fundacion', models.DateTimeField()),
            ],
            options={
                'verbose_name_plural': 'Nombre Productora',
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Realiza',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('id_evento', models.ForeignKey(to='pagina.Evento')),
                ('id_productora', models.ForeignKey(to='pagina.Productora')),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Realizado',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('id_evento', models.ForeignKey(to='pagina.Evento')),
                ('id_lugar', models.ForeignKey(to='pagina.Lugar')),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name='Tweet',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('texto_tweet', models.CharField(max_length=60)),
                ('fecha_tweet', models.DateTimeField()),
                ('id_cuenta', models.ForeignKey(to='pagina.Cuenta')),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.AddField(
            model_name='hashtag',
            name='id_productora',
            field=models.ForeignKey(to='pagina.Productora'),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='contrata',
            name='id_productora',
            field=models.ForeignKey(to='pagina.Productora'),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='contiene',
            name='id_hashtag',
            field=models.ForeignKey(to='pagina.Hashtag'),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='contiene',
            name='id_tweet',
            field=models.ForeignKey(to='pagina.Tweet'),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='asisten',
            name='id_evento',
            field=models.ForeignKey(to='pagina.Evento'),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='asisten',
            name='id_persona',
            field=models.ForeignKey(to='pagina.Persona'),
            preserve_default=True,
        ),
        migrations.AddField(
            model_name='artista',
            name='id_cuenta',
            field=models.ForeignKey(to='pagina.Cuenta'),
            preserve_default=True,
        ),
        migrations.AlterModelOptions(
            name='persona',
            options={'verbose_name_plural': 'Nombre'},
        ),
    ]
