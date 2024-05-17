# Export all scenes to DWG in SketchUp

# Function to export scenes to DWG
def export_scenes_to_dwg
    model = Sketchup.active_model
  
    # Ensure there are scenes in the model
    if model.pages.count == 0
      puts "No scenes found in the model."
      return
    end
  
    # Get the path to save the DWG files
    dwg_folder = UI.select_directory(title: "Select DWG Export Folder")
    return unless dwg_folder
  
    # Loop through all scenes and export to DWG
    model.pages.each do |scene|
      model.pages.selected_page = scene
  
      # Set the file name based on the scene name
      dwg_file_path = File.join(dwg_folder, "#{scene.name}.dwg")
  
      # Export the scene to DWG

      SketchUp.send_action(21237,dwg_file_path)
      puts "Scene '#{scene.name}' exported to '#{dwg_file_path}'."
    end
  end
  
  # Run the export function
  export_scenes_to_dwg
  