/* jQuery codes and functions used in Ecstasy Template */
(function($) {
   
   "use strict";
                    
   /* PAGE LOADER */
   $(window).load(function(){
     $('#loader').fadeOut(1500);
   });
   
     
   /* TESTIMONIAL CAROUSEL */ 
   if ( $( "#testimonial-carousel" ).length ) {
      $('#testimonial-carousel').owlCarousel({
         items:1,
         margin:10,
         loop: true,
         animateOut: 'fadeOut',
         autoplay: true,
      });
   }
   
   
   /* IMAGE CAROUSEL */
   if ( $( "#image-carousel" ).length ) {  
      $('#image-carousel').owlCarousel({
         items:1,
         margin:10,
         loop: true,
         autoplay: true,
      });
   }
    
    
   /* MENU TOGGLING */ 
   var menuRight = document.getElementById( 'cbp-spmenu-s2' ),
      openRightPush = document.getElementById( 'openRightPush' ),
      body = document.body;
      
   openRightPush.onclick = function() {
      classie.toggle( this, 'active' );
      classie.toggle( menuRight, 'cbp-spmenu-open' );
   };
         
              
   /* JCAROUSEL RESPONSIVENESS */
   $(function() {
       if ( $( ".jcarousel" ).length ) {
         var jcarousel = $('.jcarousel');
       
         jcarousel
             .on('jcarousel:reload jcarousel:create', function () {
                 var width = jcarousel.innerWidth();
       
                 if (width >= 768) {
                     width = width / 4;
                 } else if (width >= 450) {
                     width = width / 2;                                     
                 } 
       
                 jcarousel.jcarousel('items').css('width', width + 'px');
             })
             .jcarousel({
                 wrap: 'circular'
             });
   
         $('.jcarousel-control-prev')
             .jcarouselControl({
                 target: '-=1'
             });
       
         $('.jcarousel-control-next')
             .jcarouselControl({
                 target: '+=1'
             });
   
         $('.jcarousel-pagination')
             .on('jcarouselpagination:active', 'a', function() {
                 $(this).addClass('active');
             })
             .on('jcarouselpagination:inactive', 'a', function() {
                 $(this).removeClass('active');
             })
             .on('click', function(e) {
                 e.preventDefault();
             })
             .jcarouselPagination({
                 perPage: 1,
                 item: function(page) {
                     return '<a href="#' + page + '">' + page + '</a>';
                 }
             });
       }
   });
   
   
   
   /* ISOTOPE FOR PORTFOLIO ITEMS */
   if ( $( "#portfolio-grid" ).length ) {
      var $container = $('#portfolio-grid').imagesLoaded( function() {
         var isotope = function () {
            $container.isotope({
                    resizable: false,
                    itemSelector: '.entry',
            });
         };
         isotope();
      });
   
      
      $('div.portfolio-filter ul a').click(function(){
              var selector = $(this).attr('data-filter');
              $container.isotope({
                  filter: selector,
                  animationOptions: {
                     duration: 750,
                     easing: 'linear',
                     queue: false,
                  }
              });
        return false;
      });
   
      var $optionSets = $('div.portfolio-filter ul'),
             $optionLinks = $optionSets.find('a');
             $optionLinks.click(function(){
                var $this = $(this);
                // don't proceed if already selected
                if ( $this.hasClass('selected') ) {
                    return false;
                }
         var $optionSet = $this.parents('div.portfolio-filter ul');
         $optionSet.find('.selected').removeClass('selected');
         $this.addClass('selected'); 
      });
        
   }
   
   /* PORTFOLIO EXPANDER GRID INITIALIZER */
   if ( $( "#og-grid" ).length ) {
      Grid.init();
   }
   
   
   /* FUN FACTS COUNTERS */	
   jQuery(document).ready(function($) {
     if ( $( ".counter" ).length ) {
       $('.counter').counterUp({
           delay: 10,
           time: 1000
       });
     }
   });
      
   
   /* SUPER SLIDES OPTIONS */	   
   if ( $( "#slides" ).length ) {
      $('#slides').superslides({
       animation: 'fade',
       play: 5000,
      });
   }
   
         
   /* CONTACT FORM VALIDATION SCRIPT */
   $(function() {
       if ( $( "#contact" ).length ) {
         $('#contact').validate({
             
             errorElement: "em", 
             rules: {
                 name: {
                     required: true
                 },
                 email: {
                     required: true,
                     email: true
                 },
                 message: {
                     required: true
                 }
             },
             messages: {
                 name: {
                     required: ""
                 },
                 email: {
                     required: ""
                 },
                 message: {
                     required: ""
                 }
             },
   
               submitHandler: function(form) {
                   $(form).ajaxSubmit({
                       type:"POST",
                       data: $(form).serialize(),
                       url:"../include/process.php",
                 
                       success: function() {
                          
                           $('#success').fadeIn('slow', function() {
                                   setTimeout("$('#success').fadeOut('slow');", 2000);
                                   $('#contact :input').val('');
                                 
                           })
                       },
       
                       error: function() {
                           
                               $('#contact').fadeTo( "slow", 0.15, function() {
                               $('#error').fadeIn();
                           });
                       }
                   });
               }
           });
       }
   });
   
      
      
   /* GOOGLE MAP EMBEDDED IN THE CONTACT PAGE */
   
   if ( $( "#map" ).length ) {
      google.maps.event.addDomListener(window, 'load', init);
   }        
      function init() {
                  
               // insert you lattitude/longitute here
               var myLatlng = new google.maps.LatLng(43.642566, -79.387057);
               // edit the position of the marker here
               var markerPosition = new google.maps.LatLng(43.659066, -79.383057);
               var marker = new google.maps.Marker({
                     position: markerPosition,
               });
   
               var mapOptions = {
                  // How zoomed in you want the map to start at (always required)
                  zoom: 11,
       
                  // The latitude and longitude to center the map (always required)
                  center: myLatlng, // Toronto
       
                  // How you would like to style the map. 
                  // This is where you would paste any style found on Snazzy Maps.
                  styles: [
                        {
                            "featureType": "water",
                            "elementType": "geometry",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 17
                                }
                            ]
                        },
                        {
                            "featureType": "landscape",
                            "elementType": "geometry",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 20
                                }
                            ]
                        },
                        {
                            "featureType": "road.highway",
                            "elementType": "geometry.fill",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 17
                                }
                            ]
                        },
                        {
                            "featureType": "road.highway",
                            "elementType": "geometry.stroke",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 29
                                },
                                {
                                    "weight": 0.2
                                }
                            ]
                        },
                        {
                            "featureType": "road.arterial",
                            "elementType": "geometry",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 18
                                }
                            ]
                        },
                        {
                            "featureType": "road.local",
                            "elementType": "geometry",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 16
                                }
                            ]
                        },
                        {
                            "featureType": "poi",
                            "elementType": "geometry",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 21
                                }
                            ]
                        },
                        {
                            "elementType": "labels.text.stroke",
                            "stylers": [
                                {
                                    "visibility": "on"
                                },
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 16
                                }
                            ]
                        },
                        {
                            "elementType": "labels.text.fill",
                            "stylers": [
                                {
                                    "saturation": 36
                                },
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 40
                                }
                            ]
                        },
                        {
                            "elementType": "labels.icon",
                            "stylers": [
                                {
                                    "visibility": "off"
                                }
                            ]
                        },
                        {
                            "featureType": "transit",
                            "elementType": "geometry",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 19
                                }
                            ]
                        },
                        {
                            "featureType": "administrative",
                            "elementType": "geometry.fill",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 20
                                }
                            ]
                        },
                        {
                            "featureType": "administrative",
                            "elementType": "geometry.stroke",
                            "stylers": [
                                {
                                    "color": "#000000"
                                },
                                {
                                    "lightness": 17
                                },
                                {
                                    "weight": 1.2
                                }
                            ]
                        }
                    ]
               };
   
               var mapElement = document.getElementById('map');
               var map = new google.maps.Map(mapElement, mapOptions);
               marker.setMap(map); // sets the map marker
           }


})(jQuery);


   


	
