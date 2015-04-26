from django.db import models

# Create your models here.
class Productora(models.Model):
	nombre_productora= models.CharField(max_length=60)
	fecha_fundacion= models.DateTimeField()
	class Meta:
			verbose_name_plural='Nombre Productora'
	def __unicode__(self):
		return self.nombre_productora

class Cuenta(models.Model):
	nombre_cuenta=models.CharField(max_length=60)
	twitter= models.CharField(max_length=60)
	fecha_creacion= models.DateTimeField()
	class Meta:
		verbose_name_plural='Nombre Cuenta'
	def __unicode__(self):
		return self.nombre_cuenta

class Tweet(models.Model):
	texto_tweet=models.CharField(max_length=60)
	fecha_tweet= models.DateTimeField()
	id_cuenta=models.ForeignKey(Cuenta)

class Evento(models.Model):
	nombre_evento= models.CharField(max_length=60)
	class Meta:
			verbose_name_plural='Nombre Evento'
	def __unicode__(self):
		return self.nombre_evento

class Persona(models.Model):
		nombre_persona = models.CharField(max_length=60)
		fecha_nacimiento = models.DateTimeField()
		class Meta:
			verbose_name_plural='Nombre Persona'
		def __unicode__(self):
			return self.nombre_persona

class Artista(models.Model):
		nombre_artista =models.CharField(max_length=60)
		genero_musical =models.CharField(max_length=60)
		id_cuenta=models.ForeignKey(Cuenta)
		class Meta:
			verbose_name_plural='Nombre Artista'
		def __unicode__(self):
			return self.nombre_artista

class Hashtag(models.Model):
	contenido_hashtag= models.CharField(max_length=60)
	id_productora= models.ForeignKey(Productora)


class Asisten(models.Model):
		id_evento= models.ForeignKey(Evento)
		id_persona= models.ForeignKey(Persona)

class Contiene(models.Model):
	id_hashtag=models.ForeignKey(Hashtag)
	id_tweet= models.ForeignKey(Tweet)

class Contrata(models.Model):
	id_artista= models.ForeignKey(Artista)
	id_productora =models.ForeignKey(Productora)


class Cuenta_Persona(models.Model):
	id_cuenta= models.ForeignKey(Cuenta)
	id_persona= models.ForeignKey(Persona)


class Lugar(models.Model):
	nombre_lugar= models.CharField(max_length=60)
	direccion = models.CharField(max_length=60)
	class Meta:
			verbose_name_plural='Nombre Lugar'
	def __unicode__(self):
			return self.nombre_lugar

class Pais(models.Model):
	nombre_pais= models.CharField(max_length=60)
	class Meta:
			verbose_name_plural='Nombre Pais'
	def __unicode__(self):
		return self.nombre_pais

class Persona_Pais(models.Model):
	id_pais= models.ForeignKey(Pais)
	id_persona= models.ForeignKey(Persona)


class Realiza(models.Model):
	id_evento= models.ForeignKey(Evento)
	id_productora= models.ForeignKey(Productora)

class Realizado(models.Model):
	id_evento= models.ForeignKey(Evento)
	id_lugar= models.ForeignKey(Lugar)