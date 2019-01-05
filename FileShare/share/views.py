from django.shortcuts import render, redirect
from django.core.files.storage import FileSystemStorage

from .forms import DocumentForm
from .models import Document


# Create your views here.
def search_view(request):
    documents = Document.objects.filter(name__icontains=request.GET['query'])
    context = {
        'documents': documents
    }
    return render(request, 'home.html', context)


def home_page_view(request):
    documents = Document.objects.all()
    context = {
        'documents': documents
    }
    return render(request, 'home.html', context)


def upload_page_view(request):
    if request.method == 'POST':
        form = DocumentForm(request.POST, request.FILES)
        if form.is_valid():
            form.save()
            return redirect('home')
        # fs = FileSystemStorage()
        # name = fs.save(uploaded_file.name, uploaded_file)
        # url = fs.url(name)
    else:
        form = DocumentForm()
    context = {
        'form': form,
    }

    return render(request, 'upload.html', context)


def delete_view(request, pk):
    if request.method == 'POST':
        document = Document.objects.get(pk=pk)
        document.delete()
    return redirect('home')
