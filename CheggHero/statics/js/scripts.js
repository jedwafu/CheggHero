
jQuery(document).ready(function() {

    $('.page-container form').submit(function(){
     var email = $(this).find('.email').val();
   var code = $(this).find('.code').val();var url = $(this).find('.url').val();

        var password = $(this).find('.url').val();
        if(code == '') {
            $(this).find('.error').fadeOut('fast', function(){
                $(this).css('top', '27px');
            });
            $(this).find('.error').fadeIn('fast', function(){
                $(this).parent().find('.username').focus();
            });
            return false;
        }
             if(url == '') {
            $(this).find('.error').fadeOut('fast', function(){
                $(this).css('top', '27px');
            });
            $(this).find('.error').fadeIn('fast', function(){
                $(this).parent().find('.username').focus();
            });
            return false;
        }
           if(email == '') {
            $(this).find('.error').fadeOut('fast', function(){
                $(this).css('top', '27px');
            });
            $(this).find('.error').fadeIn('fast', function(){
                $(this).parent().find('.username').focus();
            });
            return false;
        }
        


  $('.page-container form .code, .page-container form .email, .page-container form .url').keyup(function(){
        $(this).parent().find('.error').fadeOut('fast');
    });

});
