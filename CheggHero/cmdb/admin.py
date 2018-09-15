from django.contrib import admin
from cmdb.models import UserInfo
# Register your models here.


class UnserInfoAdmin(admin.ModelAdmin):
    list_display = ('code', 'email', 'url') # list
    search_fields = ('code', 'email', 'url')

admin.site.register(UserInfo, UnserInfoAdmin)