from django.db import models

# Create your models here.


class UserInfo(models.Model):

    code = models.CharField(max_length=1000)
    url = models.CharField(max_length=1000)
    email = models.EmailField()
    
    def __str__(self):
        return self.code