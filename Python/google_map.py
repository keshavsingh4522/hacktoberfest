import folium
map = folium.Map(location=[27.7172, 85.3240], zoom_start=12)
folium.Marker(location=[27.7172, 85.3240], popup="Kathmandu").add_to(map)
folium.Marker(location=[27.70803355, 85.37142048523822],
              popup="Deep").add_to(map)
folium.PolyLine(locations=[(27.7172, 85.3240), (27.70803355, 85.37142048523822)],
                color="red", weight=2.5, opacity=1).add_to(map)
map.save("map.html")
map