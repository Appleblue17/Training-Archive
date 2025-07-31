export default function FileViewerPDF({ pdfPath }: { pdfPath: string }) {
  return (
    <div className="flex h-[85dvh] w-full flex-col rounded border-2 border-gray-600 bg-zinc-800">
      <iframe
        src={pdfPath}
        className="w-full flex-1"
        style={{ border: "none" }}
        title="PDF Viewer"
      />
    </div>
  );
}
