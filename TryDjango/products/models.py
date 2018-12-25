from django.db import models
from django.core.validators import MaxValueValidator, MinValueValidator
from django.urls import reverse


# Create your models here.
class Product(models.Model):
    title = models.CharField(max_length=120)
    description = models.TextField(blank=True, null=True)
    price = models.DecimalField(max_digits=1000, decimal_places=2)
    summary = models.TextField()
    featured = models.BooleanField(default=True)

    def get_absolute_url(self):
        return reverse('products:product-detail', kwargs={'id': self.id})  # f'/product/{self.id}/'


class Review(models.Model):
    rating = models.PositiveSmallIntegerField(default=1, validators=[MaxValueValidator(5), MinValueValidator(1)])
    comment = models.CharField(max_length=120)
