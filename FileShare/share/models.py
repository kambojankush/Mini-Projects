from django.db import models


# Create your models here.
class Document(models.Model):
    name = models.CharField(max_length=120)
    file = models.FileField(upload_to='documents/')

    def __str__(self):
        return self.name

    def delete(self, *args, **kwargs):
        self.file.delete()
        super().delete(*args, **kwargs)
