# Generated by Django 2.1.4 on 2018-12-19 13:58

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('products', '0003_review'),
    ]

    operations = [
        migrations.RenameModel(
            old_name='Review',
            new_name='Reviews',
        ),
    ]
